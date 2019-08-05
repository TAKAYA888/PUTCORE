#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "DeletableClass/DeletableClass.h"

class DeletableClassList
{
public:

	DeletableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void removeDestroyClass();

private:

	std::forward_list<DeletableClass> m_deletableClassList;

	std::forward_list<DeletableClass> m_addClassList;
};

template<class T>
inline void DeletableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(DeletableClass(addClass, ptr));
}