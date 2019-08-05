#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "OnDestroyableClass/OnDestroyableClass.h"

class OnDestroyableClassList
{
public:

	OnDestroyableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void onDestroyAll();

private:

	std::forward_list<OnDestroyableClass> m_onDestroyableClassList;

	std::forward_list<OnDestroyableClass> m_addClassList;
};

template<class T>
inline void OnDestroyableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(OnDestroyableClass(addClass, ptr));
}