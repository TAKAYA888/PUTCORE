#pragma once

#include "../../ComponentBase.h"

#include <memory>
#include <forward_list>
#include "../../../GameObject/GameObjectPtr.h"
#include "ChildList.h"

// 親要素、子要素を管理するコンポーネント
class ParentChildManager
	: public ComponentBase
{
public:

	ParentChildManager();

public:

	void update();

public:

	// 全ての子要素を削除する
	void removeChild(GameObjectPtr child);

	// 全ての子要素を削除する
	void removeChildren();

	// 親要素を取得する
	GameObjectPtr getParent() const;

	// 親要素を設定する
	void setParent(GameObjectPtr parent);

	// 子要素のリストを取得する
	std::forward_list<GameObjectPtr> getChildren() const;

	// 子要素を追加する
	void addChild(GameObjectPtr child);

private:

	GameObjectPtr m_parent;

	ChildList m_children;
};