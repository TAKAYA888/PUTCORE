#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "StartableClass/StartableClass.h"

class StartableClassList
{
public:

	StartableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void startAll();

private:

	std::forward_list<StartableClass> m_startableClassList;

	std::forward_list<StartableClass> m_addClassList;
};

template<class T>
inline void StartableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(StartableClass(addClass, ptr));
}