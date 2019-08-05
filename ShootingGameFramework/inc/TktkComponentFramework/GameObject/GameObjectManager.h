#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "GameObject.h"
#include "GameObjectPtr.h"
#include "GameObjectList.h"

// 全てのゲームオブジェクトのマネージャー
class GameObjectManager
{
public:

	static void initialize();

	// GameObjectのリストを更新する
	static void updateGameObjectList();

	// GameObjectを追加する
	static void addGameObject(std::shared_ptr<GameObject> addClass);

	// 引数のタグを持つGameObjectを取得する
	static GameObjectPtr findGameObjectWithTag(int tag);

	// 指定したコンテナで引数のタグを持つGameObjectを取得する
	template <template<class U, class A = std::allocator<U>> class Container>
	static Container<GameObjectPtr> findGameObjectsWithTag(int tag);

	// 全てのGameObjectにメッセージを送信する
	static void sendMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param = std::weak_ptr<void>());

private:

	static GameObjectList m_gameObjectList;
};

template<template<class U, class A = std::allocator<U>> class Container>
inline Container<GameObjectPtr> GameObjectManager::findGameObjectsWithTag(int tag)
{
	return m_gameObjectList.findWithTagAll<Container>(tag);
}
