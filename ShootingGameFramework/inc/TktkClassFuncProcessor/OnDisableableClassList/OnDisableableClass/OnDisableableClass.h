#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "OnDisableableCheck.h"

class OnDisableableClass
{
public:

	template<class T>
	OnDisableableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void onDisable();

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onDisable)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onDisable(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasOnDisableMember<T>::value>::type* = nullptr>
		static void checkToRunOnDisable(T runClass)
		{
			runClass->onDisable();
		}

		template <class T, typename std::enable_if<!HasOnDisableMember<T>::value>::type* = nullptr>
		static void checkToRunOnDisable(T runClass)
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
inline OnDisableableClass::OnDisableableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
OnDisableableClass::VTable OnDisableableClass::VTableInitializer<T>::m_vtable =
{
	&OnDisableableClass::VTableInitializer<T>::onDisable
};

template<class T>
inline void OnDisableableClass::VTableInitializer<T>::onDisable(std::weak_ptr<void> self)
{
	checkToRunOnDisable(std::reinterpret_pointer_cast<T>(self.lock()));
}