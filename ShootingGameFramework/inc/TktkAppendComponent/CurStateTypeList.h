#pragma once

#include <forward_list>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 自身のステートを管理するコンポーネント
class CurStateTypeList
	: public ComponentBase
{
public:

	CurStateTypeList() = default;

	// ステートを追加する
	void addState(int stateType);

	// ステートを削除する
	void removeState(int stateType);

	// 全てのステートを削除する
	void clearState();

	// 引数のステートを持っているか？
	bool contain(int stateType);

private:

	std::forward_list<int> m_stateTypeList;
};