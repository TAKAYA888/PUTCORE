#pragma once

#include <memory>
#include <forward_list>
#include <TktkMetaFunc/ContainerMetaFunc/ContainerAdder.h>
#include "GameObjectPtr.h"

// 全てのゲームオブジェクトのリスト
class GameObjectList
{
public:

	GameObjectList() = default;

	// 新たなGameObjectを追加する
	void add(GameObjectPtr addGameObject);

	// 削除されたGameObjectを削除する
	void removeExpandPtr();

	// 引数のタグを持つGameObjectを取得する
	GameObjectPtr findWithTag(int tag);

	// 指定したコンテナで引数のタグを持つGameObjectを取得する
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
