#pragma once

#include <memory>
#include <forward_list>
#include "../../../GameObject/GameObjectPtr.h"
#include "../../../GameObject/GameObject.h"

// �q�v�f�̃��X�g
class ChildList
{
public:

	ChildList() = default;

	// �V���Ȏq�v�f��ǉ�
	void addChild(GameObjectPtr child);

	// �q�v�f�̃��X�g���擾
	std::forward_list<GameObjectPtr> getChildren() const;

	// �폜���ꂽ�q�v�f�����X�g����폜����
	void removeExpandPtr();

	// �w��̎q�v�f���폜����
	void remove(GameObjectPtr gameObject);

	// �S�Ă̎q�v�f�����X�g����폜����
	void removeAll();

private:

	std::forward_list<GameObjectPtr> m_childList;
};