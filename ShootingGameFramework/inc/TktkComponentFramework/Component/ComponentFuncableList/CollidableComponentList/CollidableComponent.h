#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>
#include <TktkClassFuncProcessor/CollidableClassList/CollidableClass/CollidableCheck.h>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

class CollidableComponent
{
public:

	template<class T>
	CollidableComponent(std::weak_ptr<T> other);

	void onCollide(SafetyVoidSmartPtr<std::weak_ptr> other);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onCollide)(SafetyVoidSmartPtr<std::weak_ptr>, SafetyVoidSmartPtr<std::weak_ptr> other);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onCollide(SafetyVoidSmartPtr<std::weak_ptr> self, SafetyVoidSmartPtr<std::weak_ptr> other);

		template <class T, typename std::enable_if<HasOnCollideMember<T>::value>::type* = nullptr>
		static void checkToRun(T runClass, SafetyVoidSmartPtr<std::weak_ptr> other)
		{
			runClass->onCollide(other);
		}

		template <class T, typename std::enable_if<!HasOnCollideMember<T>::value>::type* = nullptr>
		static void checkToRun(T runClass, SafetyVoidSmartPtr<std::weak_ptr> other)
		{
			/* not have onCollide() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline CollidableComponent::CollidableComponent(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
CollidableComponent::VTable CollidableComponent::VTableInitializer<T>::m_vtable =
{
	&CollidableComponent::VTableInitializer<T>::onCollide
};

template<class T>
inline void CollidableComponent::VTableInitializer<T>::onCollide(SafetyVoidSmartPtr<std::weak_ptr> self, SafetyVoidSmartPtr<std::weak_ptr> other)
{
	checkToRun(self.castPtr<T>().lock(), other);
}