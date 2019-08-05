#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "UpdatableCheck.h"

class UpdatableClass
{
public:

	template<class T>
	UpdatableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void update();

	bool expiredPtr() const;

	std::type_index ptrTypeIndex() const;

private:

	struct VTable
	{
		void(*update)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void update(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasUpdateMember<T>::value>::type* = nullptr>
		static void checkToRunUpdate(T runClass)
		{
			runClass->update();
		}

		template <class T, typename std::enable_if<!HasUpdateMember<T>::value>::type* = nullptr>
		static void checkToRunUpdate(T runClass)
		{
			/* not have update() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline UpdatableClass::UpdatableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
UpdatableClass::VTable UpdatableClass::VTableInitializer<T>::m_vtable =
{ 
	&UpdatableClass::VTableInitializer<T>::update
};

template<class T>
inline void UpdatableClass::VTableInitializer<T>::update(std::weak_ptr<void> self)
{
	checkToRunUpdate(std::reinterpret_pointer_cast<T>(self.lock()));
}