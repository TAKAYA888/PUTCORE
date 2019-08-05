#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "StartableCheck.h"

class StartableClass
{
public:

	template<class T>
	StartableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void start();

	bool expiredPtr() const;

private:

	struct VTable
	{
		void(*start)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void start(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasStartMember<T>::value>::type* = nullptr>
		static void checkToRunStart(T runClass)
		{
			runClass->start();
		}

		template <class T, typename std::enable_if<!HasStartMember<T>::value>::type* = nullptr>
		static void checkToRunStart(T runClass)
		{
			/* not have start() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;

	bool m_runStart{ false };
};

template<class T>
inline StartableClass::StartableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
StartableClass::VTable StartableClass::VTableInitializer<T>::m_vtable =
{
	&StartableClass::VTableInitializer<T>::start
};

template<class T>
inline void StartableClass::VTableInitializer<T>::start(std::weak_ptr<void> self)
{
	checkToRunStart(std::reinterpret_pointer_cast<T>(self.lock()));
}