#pragma once

#include <memory>
#include <TktkComponentFramework/GameObject/GameObject.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkComponentFramework/MetaFunc/FuncableList/HaveSetActiveClassList/HaveSetActiveClassList.h>
#include "CurStateTypeList.h"

// �X�e�[�g�}�V�[���R���|�[�l���g
// �y�O��R���|�[�l���g�FCurStateTypeList�z
class StateMachine
	: public ComponentBase
{
public:

	// std::shared_ptr<StateMachine>�𐶐�����
	static std::weak_ptr<StateMachine> create(
		GameObjectPtr user,
		int stateType	// ���̃X�e�[�g�}�V���̃X�e�[�g�^�C�v
	);

public:

	StateMachine(
		int stateType	// ���̃X�e�[�g�}�V���̃X�e�[�g�^�C�v
	);

public:

	void update();

public:

	// ���̃X�e�[�g�Ɏq�v�f��ǉ�����
	void addChild(GameObjectPtr child);

	// ���̃X�e�[�g�ɃR���|�[�l���g��ǉ�����
	template <class T>
	void addComponent(std::shared_ptr<T> component);

private:

	int m_selfStateType;

	std::weak_ptr<CurStateTypeList> m_curStateTypeList;

	HaveSetActiveClassList m_haveSetActiveClassList;
};

template<class T>
inline void StateMachine::addComponent(std::shared_ptr<T> component)
{
	auto obj = getGameObject();

	getGameObject().lock()->addComponent(component);

	std::weak_ptr<T> weakPtr = component;

	m_haveSetActiveClassList.checkAndAdd(weakPtr);
}
