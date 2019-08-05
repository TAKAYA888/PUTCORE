#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../../../GameObject/GameObjectPtr.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"

class HaveCollisionExitComponent
{
public:

	template <class T>
	HaveCollisionExitComponent(std::weak_ptr<T> other);

	void onCollisionExit(GameObjectPtr other);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onCollisionExit)(SafetyVoidSmartPtr<std::weak_ptr>, GameObjectPtr other);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onCollisionExit(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other);

		template <class T, typename std::enable_if<HasCollisionExitMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			runClass.lock()->onCollisionExit(other);
		}

		template <class T, typename std::enable_if<!HasCollisionExitMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, GameObjectPtr other)
		{
			/* not have onCollisionExit() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline HaveCollisionExitComponent::HaveCollisionExitComponent(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
HaveCollisionExitComponent::VTable HaveCollisionExitComponent::VTableInitializer<T>::m_vtable =
{
	&HaveCollisionExitComponent::VTableInitializer<T>::onCollisionExit
};

template <class T>
inline void HaveCollisionExitComponent::VTableInitializer<T>::onCollisionExit(SafetyVoidSmartPtr<std::weak_ptr> self, GameObjectPtr other)
{
	checkAndRun(self.castPtr<T>(), other);
}