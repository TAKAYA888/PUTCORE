#pragma once

#include <memory>
#include <typeindex>
#include <type_traits>

#include "../../ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "DrawableCheck.h"

class DrawableClass
{
public:

	template<class T>
	DrawableClass(std::weak_ptr<ProcessingClass> processingClassPtr, float drawPriority, T*);

	void draw() const;

	bool expiredPtr() const;

	std::type_index ptrTypeIndex() const;

	float getDrawPriority() const;

private:

	struct VTable
	{
		void(*draw)(std::weak_ptr<void>);
	};

	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		static void draw(std::weak_ptr<void> self);

		template <class T, typename std::enable_if<HasDrawMember<T>::value>::type* = nullptr>
		static void checkToRunDraw(T updateClass)
		{
			updateClass->draw();
		}

		template <class T, typename std::enable_if<!HasDrawMember<T>::value>::type* = nullptr>
		static void checkToRunDraw(T updateClass)
		{
			/* not have draw() */
		}
	};

private:

	std::weak_ptr<ProcessingClass> m_processingClassPtr;

	VTable* m_vtablePtr;

	float m_drawPriority;
};

template<class T>
inline DrawableClass::DrawableClass(std::weak_ptr<ProcessingClass> processingClassPtr, float drawPriority, T*)
	: m_processingClassPtr(processingClassPtr)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
	, m_drawPriority(drawPriority)
{
}

template <class T>
DrawableClass::VTable DrawableClass::VTableInitializer<T>::m_vtable =
{
	&DrawableClass::VTableInitializer<T>::draw
};

template<class T>
inline void DrawableClass::VTableInitializer<T>::draw(std::weak_ptr<void> self)
{
	checkToRunDraw(std::reinterpret_pointer_cast<T>(self.lock()));
}