#pragma once

#include <forward_list>
#include <TktkComponentFramework/Component/ComponentBase.h>

// ���g�̃X�e�[�g���Ǘ�����R���|�[�l���g
class CurStateTypeList
	: public ComponentBase
{
public:

	CurStateTypeList() = default;

	// �X�e�[�g��ǉ�����
	void addState(int stateType);

	// �X�e�[�g���폜����
	void removeState(int stateType);

	// �S�ẴX�e�[�g���폜����
	void clearState();

	// �����̃X�e�[�g�������Ă��邩�H
	bool contain(int stateType);

private:

	std::forward_list<int> m_stateTypeList;
};