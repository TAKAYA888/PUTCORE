#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <map>
#include <unordered_map>
#include "AfterCollidableClass/AfterCollidableClass.h"

class AfterCollidableClassList
{
public:

	AfterCollidableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	template <class T>
	void addPriority(float priority);

	void addNewClass();

	void removeExpandPtr();

	void afterCollideAll();

private:

	std::multimap<float, AfterCollidableClass> m_afterCollidableClassMap;

	std::forward_list<AfterCollidableClass> m_addClassList;

private:

	static float getPriority(AfterCollidableClass target);

	static std::unordered_map<std::type_index, float> m_afterCollidePriorityMap;
};

template<class T>
inline void AfterCollidableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(AfterCollidableClass(addClass, ptr));
}

template<class T>
inline void AfterCollidableClassList::addPriority(float priority)
{
	m_afterCollidePriorityMap[typeid(T)] = priority;
}