#pragma once

#include "../../ComponentBase.h"

#include <memory>
#include <forward_list>
#include "../../../GameObject/GameObjectPtr.h"
#include "ChildList.h"

// �e�v�f�A�q�v�f���Ǘ�����R���|�[�l���g
class ParentChildManager
	: public ComponentBase
{
public:

	ParentChildManager();

public:

	void update();

public:

	// �S�Ă̎q�v�f���폜����
	void removeChild(GameObjectPtr child);

	// �S�Ă̎q�v�f���폜����
	void removeChildren();

	// �e�v�f���擾����
	GameObjectPtr getParent() const;

	// �e�v�f��ݒ肷��
	void setParent(GameObjectPtr parent);

	// �q�v�f�̃��X�g���擾����
	std::forward_list<GameObjectPtr> getChildren() const;

	// �q�v�f��ǉ�����
	void addChild(GameObjectPtr child);

private:

	GameObjectPtr m_parent;

	ChildList m_children;
};