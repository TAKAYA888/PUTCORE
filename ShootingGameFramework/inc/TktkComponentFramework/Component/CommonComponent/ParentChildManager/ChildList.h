#pragma once

#include <memory>
#include <forward_list>
#include "../../../GameObject/GameObjectPtr.h"
#include "../../../GameObject/GameObject.h"

// 子要素のリスト
class ChildList
{
public:

	ChildList() = default;

	// 新たな子要素を追加
	void addChild(GameObjectPtr child);

	// 子要素のリストを取得
	std::forward_list<GameObjectPtr> getChildren() const;

	// 削除された子要素をリストから削除する
	void removeExpandPtr();

	// 指定の子要素を削除する
	void remove(GameObjectPtr gameObject);

	// 全ての子要素をリストから削除する
	void removeAll();

private:

	std::forward_list<GameObjectPtr> m_childList;
};