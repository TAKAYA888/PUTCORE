#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>
#include <TktkClassFuncProcessor/MessageableClassList/MessageableClass/MessageableCheck.h>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

class MessageableComponent
{
public:

	template<class T>
	MessageableComponent(std::weak_ptr<T> other);

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*handleMessage)(SafetyVoidSmartPtr<std::weak_ptr>, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void handleMessage(SafetyVoidSmartPtr<std::weak_ptr> self, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

		template <class T, typename std::enable_if<HasHandleMessageMember<T>::value>::type* = nullptr>
		static void checkToRun(T runClass, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
		{
			runClass->handleMessage(eventMessageType, param);
		}

		template <class T, typename std::enable_if<!HasHandleMessageMember<T>::value>::type* = nullptr>
		static void checkToRun(T runClass, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
		{
			/* not have update() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline MessageableComponent::MessageableComponent(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
MessageableComponent::VTable MessageableComponent::VTableInitializer<T>::m_vtable =
{
	&MessageableComponent::VTableInitializer<T>::handleMessage
};

template<class T>
inline void MessageableComponent::VTableInitializer<T>::handleMessage(SafetyVoidSmartPtr<std::weak_ptr> self, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	checkToRun(self.castPtr<T>(), eventMessageType, param);
}