#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "ActiveCheckableClass/ActiveCheckableClass.h"

class ActiveCheckableClassList
{
public:

	ActiveCheckableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void activeJudgeAll();

private:

	std::forward_list<ActiveCheckableClass> m_activeCheckableClassList;

	std::forward_list<ActiveCheckableClass> m_addClassList;
};

template<class T>
inline void ActiveCheckableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(ActiveCheckableClass(addClass, ptr));
}