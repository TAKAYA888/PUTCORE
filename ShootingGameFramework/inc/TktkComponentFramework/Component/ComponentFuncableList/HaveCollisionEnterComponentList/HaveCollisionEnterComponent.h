#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../../../GameObject/GameObjectPtr.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"

class HaveCollisionEnterComponent
{
public:

	template <class T>
	HaveCollisionEnterComponent(std::weak_ptr<T> other);

	void onCollisionEnter(GameObjectPtr other);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onCollisionEnter)(SafetyVoidSmartPtr<std::weak_ptr>, GameObjectPtr other);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onCollisionEnter(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other);

		template <class T, typename std::enable_if<HasCollisionEnterMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			runClass.lock()->onCollisionEnter(other);
		}

		template <class T, typename std::enable_if<!HasCollisionEnterMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			/* not have onCollisionEnter() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline HaveCollisionEnterComponent::HaveCollisionEnterComponent(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
HaveCollisionEnterComponent::VTable HaveCollisionEnterComponent::VTableInitializer<T>::m_vtable =
{
	&HaveCollisionEnterComponent::VTableInitializer<T>::onCollisionEnter
};

template <class T>
inline void HaveCollisionEnterComponent::VTableInitializer<T>::onCollisionEnter(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other)
{
	checkAndRun(self.castPtr<T>(), other);
}