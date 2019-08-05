#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <map>
#include <unordered_map>
#include "UpdatableClass/UpdatableClass.h"

class UpdatableClassList
{
public:

	UpdatableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	template <class T>
	void addPriority(float priority);

	void addNewClass();

	void removeExpandPtr();

	void updateAll();

private:

	std::multimap<float, UpdatableClass> m_updatableClassMap;

	std::forward_list<UpdatableClass> m_addClassList;

private:

	static float getPriority(UpdatableClass target);

	static std::unordered_map<std::type_index, float> m_updatePriorityMap;
};

template<class T>
inline void UpdatableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(UpdatableClass(addClass, ptr));
}

template<class T>
inline void UpdatableClassList::addPriority(float priority)
{
	m_updatePriorityMap[typeid(T)] = priority;
}