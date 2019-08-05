#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "ActiveCheckableCheck.h"

class ActiveCheckableClass
{
public:

	template<class T>
	ActiveCheckableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void activeJudge();

	bool expiredPtr() const;

private:

	struct VTable
	{
		bool(*isActive)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static bool isActive(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasIsActiveMember<T>::value>::type* = nullptr>
		static bool checkToRunIsActive(T runClass)
		{
			return runClass->isActive();
		}

		template <class T, typename std::enable_if<!HasIsActiveMember<T>::value>::type* = nullptr>
		static bool checkToRunIsActive(T runClass)
		{
			return true;
			/* not have update() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline ActiveCheckableClass::ActiveCheckableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
ActiveCheckableClass::VTable ActiveCheckableClass::VTableInitializer<T>::m_vtable =
{
	&ActiveCheckableClass::VTableInitializer<T>::isActive
};

template<class T>
inline bool ActiveCheckableClass::VTableInitializer<T>::isActive(std::weak_ptr<void> self)
{
	return checkToRunIsActive(std::reinterpret_pointer_cast<T>(self.lock()));
}