#pragma once

#include <memory>
#include <TktkComponentFramework/GameObject/GameObject.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include <TktkComponentFramework/MetaFunc/FuncableList/HaveSetActiveClassList/HaveSetActiveClassList.h>
#include "CurStateTypeList.h"

// ステートマシーンコンポーネント
// 【前提コンポーネント：CurStateTypeList】
class StateMachine
	: public ComponentBase
{
public:

	// std::shared_ptr<StateMachine>を生成する
	static std::weak_ptr<StateMachine> create(
		GameObjectPtr user,
		int stateType	// このステートマシンのステートタイプ
	);

public:

	StateMachine(
		int stateType	// このステートマシンのステートタイプ
	);

public:

	void update();

public:

	// このステートに子要素を追加する
	void addChild(GameObjectPtr child);

	// このステートにコンポーネントを追加する
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
