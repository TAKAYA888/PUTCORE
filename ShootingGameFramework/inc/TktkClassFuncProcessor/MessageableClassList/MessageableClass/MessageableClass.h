#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "MessageableCheck.h"

class MessageableClass
{
public:

	template<class T>
	MessageableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*handleMessage)(std::weak_ptr<void>, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void handleMessage(std::weak_ptr<void> self, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

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

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline MessageableClass::MessageableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
MessageableClass::VTable MessageableClass::VTableInitializer<T>::m_vtable =
{
	&MessageableClass::VTableInitializer<T>::handleMessage
};

template<class T>
inline void MessageableClass::VTableInitializer<T>::handleMessage(std::weak_ptr<void> self, int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param)
{
	checkToRun(std::reinterpret_pointer_cast<T>(self.lock()), eventMessageType, param);
}