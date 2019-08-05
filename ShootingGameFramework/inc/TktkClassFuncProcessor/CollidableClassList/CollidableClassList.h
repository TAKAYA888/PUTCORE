#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "CollisionGroupList.h"
#include "CollidableClass/CollidableClass.h"

class CollidableClassList
{
public:

	CollidableClassList() = default;

	template <class T>
	void add(int collisionGroupType, std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addCollisionGroup(int collisionGroupType);

	void addCollisionGroupPair(int groupOne, int groupTwo);

	void addNewClass();

	void removeExpandPtr();

	void collideAll();

private:

	std::forward_list<std::pair<int, int>> m_CollisionGroupPairList;

	std::unordered_map<int, CollisionGroupList> m_collisionGroupListMap;

	std::forward_list<std::pair<int, CollidableClass>> m_addClassList;
};

template<class T>
inline void CollidableClassList::add(int collisionGroupType, std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(std::make_pair(collisionGroupType, CollidableClass(addClass, ptr)));
}
