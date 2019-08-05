#pragma once

#include <forward_list>
#include "CollidableClass/CollidableClass.h"

class CollisionGroupList
{
public:

	std::forward_list<CollidableClass>::iterator begin();
	std::forward_list<CollidableClass>::iterator end();

public:

	CollisionGroupList() = default;

	void add(const CollidableClass& addClass);

	void removeExpandPtr();

	void collisionOther(CollisionGroupList other);

private:

	std::forward_list<CollidableClass> m_collisionGroupList;
};
