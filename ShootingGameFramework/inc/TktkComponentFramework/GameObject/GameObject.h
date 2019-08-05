#pragma once

#include <memory>
#include <forward_list>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../Component/ComponentList.h"
#include "../Component/ComponentMetaFunc/ComponentUserSetter.h"
#include "GameObjectPtr.h"

// �Q�[���I�u�W�F�N�g�N���X
class GameObject
	: public std::enable_shared_from_this<GameObject>
{
public:

	// �Q�[���I�u�W�F�N�g�𐶐�����
	static GameObjectPtr create();

public:

	GameObject();
	virtual ~GameObject();

	// �e�q�֌W�֐�
public:

	// �e�v�f���擾
	GameObjectPtr getParent() const;

	// �e�v�f��ݒ�
	void setParent(GameObjectPtr parent);

	// �q�v�f�̃��X�g���擾
	std::forward_list<GameObjectPtr> getChildren() const;

	// �q�v�f�����X�g�ɒǉ�����
	void addChild(GameObjectPtr child);

	// �w�肵���q�v�f�����X�g����폜����
	void removeChild(GameObjectPtr child);

	// �S�Ă̎q�v�f�Ƀ��b�Z�[�W�𑗐M����
	void sendMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param = std::weak_ptr<void>());

	// �R���|�[�l���g�֘A�֐�
public:

	// �e���v���[�g�p�����[�^�̃R���|�[�l���g���擾����
	template <class T>
	std::weak_ptr<T> getComponent() const;

	// �R���|�[�l���g��ǉ�����
	template <class T>
	void addComponent(std::shared_ptr<T> component);

	// �S�ẴR���|�[�l���g�̏ՓˊJ�n�֐����Ă�
	void runOnCollisionEnterAll(GameObjectPtr other);

	// �S�ẴR���|�[�l���g�̏Փ˒��֐����Ă�
	void runOnCollisionStayAll(GameObjectPtr other);

	// �S�ẴR���|�[�l���g�̏ՓˏI���֐����Ă�
	void runOnCollisionExitAll(GameObjectPtr other);

	// ���̑��p�����[�^�ݒ�/�擾�֐�
public:

	// ���g�̃^�O���擾
	int getTag() const;

	// �폜�t���O���擾
	bool isDestroy() const;

	// �A�N�e�B�u�t���O���擾
	bool isActive() const;
	
	// ���g�̃^�O��ݒ�
	void setTag(int tag);

	// ���g���폜����
	void destroy();

	// �A�N�e�B�u�t���O��ݒ肷��
	void setActive(bool isActive);

	// �|�����[�t�B�Y���Ȋ֐�
public:

	void awake();

	void update();

	void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

	void onDestroy();

private:

	int m_tag{ 0 };
	bool m_isDestroy{ false };
	bool m_isActive{ true };

	ComponentList m_componentList;
};

template<class T>
inline std::weak_ptr<T> GameObject::getComponent() const
{
	return m_componentList.getComponent<T>();
}

template<class T>
inline void GameObject::addComponent(std::shared_ptr<T> component)
{
	m_componentList.add(component);
	ComponentUserSetter::checkToSet(component, weak_from_this());
}
