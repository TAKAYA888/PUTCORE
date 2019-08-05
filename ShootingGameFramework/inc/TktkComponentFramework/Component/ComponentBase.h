#pragma once

#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../GameObject/GameObjectPtr.h"
#include "../GameObject/GameObject.h"

/* 
�R���|�[�l���g�̊��N���X
<PolymorphismFunc>

void awake();
void start();
void onEnable();
void onDisable();
void onDestroy();

void update();
void onCollisionEnter(GameObjectPtr other);
void onCollisionStay(GameObjectPtr other);
void onCollisionExit(GameObjectPtr other);
void handleMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);
*/
class ComponentBase
	: public std::enable_shared_from_this<ComponentBase>
{
public:

	ComponentBase(
		float drawPriority = 0.0f,	// �`�悷�郌�C���[
		int collisionGroupType = 0	// �Փ˔���̃O���[�v
	);

	virtual ~ComponentBase();

public:

	// �폜�t���O�̎擾
	bool isDestroy() const;

	// �A�N�e�B�u�t���O�̎擾
	bool isActive() const;

	// �폜����
	void destroy();

	// �A�N�e�B�u�t���O��ݒ�
	void setActive(bool isActive);

	// �`�悷�郌�C���[���擾
	float getDrawPriority() const;

	// �Փ˔���̃O���[�v���擾
	int getCollisionGroupType() const;

	// GameObject���擾
	GameObjectPtr getGameObject() const;

	// ���g�̏����҂ƂȂ�GameObject���Đݒ�i�񐄏��j
	void setGameObject(GameObjectPtr user);

public:

	// �e���v���[�g�p�����[�^�̃R���|�[�l���g���擾����
	template <class T>
	std::weak_ptr<T> getComponent() const;

private:

	bool m_isDestroy{ false };
	bool m_isActive{ true };

	GameObjectPtr m_user;

	float m_drawPriority{ 0.0f };

	int m_collisionGroupType { 0 };
};

template<class T>
inline std::weak_ptr<T> ComponentBase::getComponent() const
{
	return getGameObject().lock()->getComponent<T>();
}