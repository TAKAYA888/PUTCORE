#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "OnDisableableClass/OnDisableableClass.h"

class OnDisableableClassList
{
public:

	OnDisableableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void onDisableAll();

private:

	std::forward_list<OnDisableableClass> m_onDisableableClassListh;

	std::forward_list<OnDisableableClass> m_addClassList;
};

template<class T>
inline void OnDisableableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(OnDisableableClass(addClass, ptr));
}