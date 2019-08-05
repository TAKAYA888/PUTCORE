#pragma once

#include <memory>
#include <list>
#include <forward_list>
#include <algorithm>
#include <TktkMetaFunc/ContainerMetaFunc/ContainerAdder.h>
#include "ProcessingClass/ProcessingClass.h"

class ProcessingClassList
{
public:

	ProcessingClassList() = default;

	void addNewClass();

	void removeDestroyClass();

	void add(std::shared_ptr<ProcessingClass> addClass);

	template <class T>
	void remove(std::weak_ptr<T> removeClass);

	template <class T, template<class U, class A = std::allocator<U>> class Container>
	void removeAll(Container<std::weak_ptr<T>> removeClassContainer);

	template <class T>
	std::weak_ptr<T> find() const;

	template <class T, template<class U, class A = std::allocator<U>> class Container>
	Container<std::weak_ptr<T>> findAll() const;

private:

	std::list<std::shared_ptr<ProcessingClass>> m_processingClassPtrList;

	std::forward_list<std::shared_ptr<ProcessingClass>> m_addClassList;
};

template<class T>
inline void ProcessingClassList::remove(std::weak_ptr<T> removeClass)
{
	for (auto& processingClass : m_processingClassPtrList)
	{
		if (processingClass->isSame(removeClass)) processingClass->destroy();
	}
}

template<class T, template<class U, class A = std::allocator<U>> class Container>
inline void ProcessingClassList::removeAll(Container<std::weak_ptr<T>> removeClassContainer)
{
	for (const auto& removeClass : removeClassContainer)
	{
		remove(removeClass);
	}
}

template<class T>
inline std::weak_ptr<T> ProcessingClassList::find() const
{
	auto curItr = std::begin(m_processingClassPtrList);
	auto endItr = std::end(m_processingClassPtrList);

	auto result = std::find_if(curItr, endItr, [](std::shared_ptr<ProcessingClass> x) { return x->canCast<T>(); });

	if (result == endItr) return std::weak_ptr<T>();

	return (*result)->castPtr<T>();
}

template<class T, template<class U, class A = std::allocator<U>> class Container>
inline Container<std::weak_ptr<T>> ProcessingClassList::findAll() const
{
	Container<std::weak_ptr<T>> resultList;

	auto curItr = std::begin(m_processingClassPtrList);
	auto endItr = std::end(m_processingClassPtrList);

	while (true)
	{
		auto result = std::find_if(curItr, endItr, [](std::shared_ptr<ProcessingClass> x) { return x->canCast<T>(); });

		if (result == endItr) break;

		ContainerAdder::checkToAdd(resultList, (*result)->castPtr<T>());

		curItr = ++result;
	}
	return resultList;
}