#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "GameObject.h"
#include "GameObjectPtr.h"
#include "GameObjectList.h"

// �S�ẴQ�[���I�u�W�F�N�g�̃}�l�[�W���[
class GameObjectManager
{
public:

	static void initialize();

	// GameObject�̃��X�g���X�V����
	static void updateGameObjectList();

	// GameObject��ǉ�����
	static void addGameObject(std::shared_ptr<GameObject> addClass);

	// �����̃^�O������GameObject���擾����
	static GameObjectPtr findGameObjectWithTag(int tag);

	// �w�肵���R���e�i�ň����̃^�O������GameObject���擾����
	template <template<class U, class A = std::allocator<U>> class Container>
	static Container<GameObjectPtr> findGameObjectsWithTag(int tag);

	// �S�Ă�GameObject�Ƀ��b�Z�[�W�𑗐M����
	static void sendMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param = std::weak_ptr<void>());

private:

	static GameObjectList m_gameObjectList;
};

template<template<class U, class A = std::allocator<U>> class Container>
inline Container<GameObjectPtr> GameObjectManager::findGameObjectsWithTag(int tag)
{
	return m_gameObjectList.findWithTagAll<Container>(tag);
}
