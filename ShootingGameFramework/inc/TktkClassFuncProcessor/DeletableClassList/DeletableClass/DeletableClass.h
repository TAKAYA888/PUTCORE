#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "DeletableCheck.h"

class DeletableClass
{
public:

	template<class T>
	DeletableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	void destroyJudge();

	bool expiredPtr() const;

private:

	struct VTable
	{
		bool(*isDestroy)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static bool isDestroy(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasIsDestroyMember<T>::value>::type* = nullptr>
		static bool checkToRunIsDestroy(T runClass)
		{
			return runClass->isDestroy();
		}

		template <class T, typename std::enable_if<!HasIsDestroyMember<T>::value>::type* = nullptr>
		static bool checkToRunIsDestroy(T runClass)
		{
			/* not have update() */
			return false;
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline DeletableClass::DeletableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
DeletableClass::VTable DeletableClass::VTableInitializer<T>::m_vtable =
{
	&DeletableClass::VTableInitializer<T>::isDestroy
};

template<class T>
inline bool DeletableClass::VTableInitializer<T>::isDestroy(std::weak_ptr<void> self)
{
	return checkToRunIsDestroy(std::reinterpret_pointer_cast<T>(self.lock()));
}