#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../../../GameObject/GameObjectPtr.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"

class HaveCollisionStayComponent
{
public:

	template <class T>
	HaveCollisionStayComponent(std::weak_ptr<T> other);

	void onCollisionStay(GameObjectPtr other);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onCollisionStay)(SafetyVoidSmartPtr<std::weak_ptr>, GameObjectPtr other);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onCollisionStay(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other);

		template <class T, typename std::enable_if<HasCollisionStayMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			runClass.lock()->onCollisionStay(other);
		}

		template <class T, typename std::enable_if<!HasCollisionStayMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			/* not have onCollisionStay() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline HaveCollisionStayComponent::HaveCollisionStayComponent(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
HaveCollisionStayComponent::VTable HaveCollisionStayComponent::VTableInitializer<T>::m_vtable =
{
	&HaveCollisionStayComponent::VTableInitializer<T>::onCollisionStay
};

template <class T>
inline void HaveCollisionStayComponent::VTableInitializer<T>::onCollisionStay(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other)
{
	checkAndRun(self.castPtr<T>(), other);
}