#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "CollidableCheck.h"

class CollidableClass
{
public:

	template<class T>
	CollidableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*);

	bool isCollide(const CollidableClass& other);

	void onCollide(SafetyVoidSmartPtr<std::weak_ptr> other);

	bool expiredPtr() const;

	SafetyVoidSmartPtr<std::weak_ptr> voidPtr() const;

private:

	struct VTable
	{
		bool(*isCollide)(std::weak_ptr<void>, const SafetyVoidSmartPtr<std::weak_ptr> other);
		void(*onCollide)(std::weak_ptr<void>, SafetyVoidSmartPtr<std::weak_ptr> other);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static bool isCollide(std::weak_ptr<void> self, const SafetyVoidSmartPtr<std::weak_ptr> other);
		static void onCollide(std::weak_ptr<void> self, SafetyVoidSmartPtr<std::weak_ptr> other);

		template <class T, typename std::enable_if<HasIsCollideMember<T>::value>::type* = nullptr>
		static bool checkToIsCollide(T runClass, const SafetyVoidSmartPtr<std::weak_ptr> otherClass)
		{
			return runClass->isCollide(otherClass);
		}

		template <class T, typename std::enable_if<!HasIsCollideMember<T>::value>::type* = nullptr>
		static bool checkToIsCollide(T runClass, const SafetyVoidSmartPtr<std::weak_ptr> otherClass)
		{
			/* not have isCollide() */
			return false;
		}

		template <class T, typename std::enable_if<HasOnCollideMember<T>::value>::type* = nullptr>
		static void checkToOnCollide(T runClass, SafetyVoidSmartPtr<std::weak_ptr> otherClass)
		{
			runClass->onCollide(otherClass);
		}

		template <class T, typename std::enable_if<!HasOnCollideMember<T>::value>::type* = nullptr>
		static void checkToOnCollide(T runClass, SafetyVoidSmartPtr<std::weak_ptr> otherClass)
		{
			/* not have onCollide() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;
};

template<class T>
inline CollidableClass::CollidableClass(std::weak_ptr<ProcessingClass> processingClassPtr, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
CollidableClass::VTable CollidableClass::VTableInitializer<T>::m_vtable =
{
	&CollidableClass::VTableInitializer<T>::isCollide,
	&CollidableClass::VTableInitializer<T>::onCollide
};

template<class T>
inline bool CollidableClass::VTableInitializer<T>::isCollide(std::weak_ptr<void> self, const SafetyVoidSmartPtr<std::weak_ptr> other)
{
	return checkToIsCollide(std::reinterpret_pointer_cast<T>(self.lock()), other);
}

template<class T>
inline void CollidableClass::VTableInitializer<T>::onCollide(std::weak_ptr<void> self, SafetyVoidSmartPtr<std::weak_ptr> other)
{
	checkToOnCollide(std::reinterpret_pointer_cast<T>(self.lock()), other);
}