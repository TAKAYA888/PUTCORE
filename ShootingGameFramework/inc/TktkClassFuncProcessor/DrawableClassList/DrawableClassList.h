#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <map>
#include "DrawableClass/DrawableClass.h"

class DrawableClassList
{
public:

	DrawableClassList() = default;

	template <class T>
	void add(float drawPriority, std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void drawAll();

private:

	std::multimap<float, DrawableClass> m_drawableClassMap;

	std::forward_list<DrawableClass> m_addClassList;
};

template<class T>
inline void DrawableClassList::add(float drawPriority, std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(DrawableClass(addClass, drawPriority, ptr));
}