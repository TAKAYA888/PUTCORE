#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "AfterCollidableCheck.h"

class AfterCollidableClass
{
public:

	template<class T>
	AfterCollidableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void afterCollide();

	bool expiredPtr() const;

	std::type_index ptrTypeIndex() const;

private:

	struct VTable
	{
		void(*afterCollide)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void afterCollide(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasAfterCollideMember<T>::value>::type* = nullptr>
		static void checkToRunAfterCollide(T runClass)
		{
			runClass->afterCollide();
		}

		template <class T, typename std::enable_if<!HasAfterCollideMember<T>::value>::type* = nullptr>
		static void checkToRunAfterCollide(T runClass)
		{
			/* not have update() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline AfterCollidableClass::AfterCollidableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
AfterCollidableClass::VTable AfterCollidableClass::VTableInitializer<T>::m_vtable =
{
	&AfterCollidableClass::VTableInitializer<T>::afterCollide
};

template<class T>
inline void AfterCollidableClass::VTableInitializer<T>::afterCollide(std::weak_ptr<void> self)
{
	checkToRunAfterCollide(std::reinterpret_pointer_cast<T>(self.lock()));
}