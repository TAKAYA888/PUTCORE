#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "OnEnableableCheck.h"

class OnEnableableClass
{
public:

	template<class T>
	OnEnableableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void onEnable();

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onEnable)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onEnable(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasOnEnableMember<T>::value>::type* = nullptr>
		static void checkToRunOnEnable(T runClass)
		{
			runClass->onEnable();
		}

		template <class T, typename std::enable_if<!HasOnEnableMember<T>::value>::type* = nullptr>
		static void checkToRunOnEnable(T runClass)
		{
			/* not have start() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;

	bool m_preFrameActive{ false };
};

template<class T>
inline OnEnableableClass::OnEnableableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
OnEnableableClass::VTable OnEnableableClass::VTableInitializer<T>::m_vtable =
{
	&OnEnableableClass::VTableInitializer<T>::onEnable
};

template<class T>
inline void OnEnableableClass::VTableInitializer<T>::onEnable(std::weak_ptr<void> self)
{
	checkToRunOnEnable(std::reinterpret_pointer_cast<T>(self.lock()));
}