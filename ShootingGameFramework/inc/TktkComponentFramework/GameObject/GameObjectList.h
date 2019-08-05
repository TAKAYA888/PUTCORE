#pragma once

#include <memory>
#include <forward_list>
#include <TktkMetaFunc/ContainerMetaFunc/ContainerAdder.h>
#include "GameObjectPtr.h"

// �S�ẴQ�[���I�u�W�F�N�g�̃��X�g
class GameObjectList
{
public:

	GameObjectList() = default;

	// �V����GameObject��ǉ�����
	void add(GameObjectPtr addGameObject);

	// �폜���ꂽGameObject���폜����
	void removeExpandPtr();

	// �����̃^�O������GameObject���擾����
	GameObjectPtr findWithTag(int tag);

	// �w�肵���R���e�i�ň����̃^�O������GameObject���擾����
	template <template<class T, class A = std::allocator<T>> class Container>
	Container<GameObjectPtr> findWithTagAll (int tag);

private:

	std::forward_list<GameObjectPtr> m_gameObjectList;
};

template<template<class T, class A = std::allocator<T>> class Container>
inline Container<GameObjectPtr> GameObjectList::findWithTagAll(int tag)
{
	Container<GameObjectPtr> resultList;

	for (auto & gameObject : m_gameObjectList)
	{
		if (!gameObject.expired() && gameObject.lock()->getTag() == tag) ContainerAdder::checkToAdd(resultList, gameObject);
	}
	return resultList;
}
