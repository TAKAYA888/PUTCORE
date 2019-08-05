#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "OnDestroyableCheck.h"

class OnDestroyableClass
{
public:

	template<class T>
	OnDestroyableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void onDestroy();

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*onDestroy)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void onDestroy(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasOnDestroyMember<T>::value>::type* = nullptr>
		static void checkToRunOnDestroy(T runClass)
		{
			runClass->onDestroy();
		}

		template <class T, typename std::enable_if<!HasOnDestroyMember<T>::value>::type* = nullptr>
		static void checkToRunOnDestroy(T runClass)
		{
			/* not have onDestroy() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline OnDestroyableClass::OnDestroyableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
OnDestroyableClass::VTable OnDestroyableClass::VTableInitializer<T>::m_vtable =
{
	&OnDestroyableClass::VTableInitializer<T>::onDestroy
};

template<class T>
inline void OnDestroyableClass::VTableInitializer<T>::onDestroy(std::weak_ptr<void> self)
{
	checkToRunOnDestroy(std::reinterpret_pointer_cast<T>(self.lock()));
}