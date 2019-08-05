#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "OnEnableableClass/OnEnableableClass.h"

class OnEnableableClassList
{
public:

	OnEnableableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void onEnableAll();

private:

	std::forward_list<OnEnableableClass> m_onEnableableClassList;

	std::forward_list<OnEnableableClass> m_addClassList;
};

template<class T>
inline void OnEnableableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(OnEnableableClass(addClass, ptr));
}