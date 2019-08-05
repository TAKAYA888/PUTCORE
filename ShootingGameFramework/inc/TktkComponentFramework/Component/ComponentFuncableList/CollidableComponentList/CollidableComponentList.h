#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "CollidableComponent.h"

class CollidableComponentList
{
public:

	CollidableComponentList() = default;

	template <class T>
	void add(std::weak_ptr<T> addClass);

	void removeExpandPtr();

	void onCollideAll(SafetyVoidSmartPtr<std::weak_ptr> other);

private:

	std::forward_list<CollidableComponent> m_collidableComponentList;
};

template<class T>
inline void CollidableComponentList::add(std::weak_ptr<T> addClass)
{
	m_collidableComponentList.push_front(CollidableComponent(addClass));
}