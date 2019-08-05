#pragma once

#include <memory>
#include <forward_list>
#include "HaveSetActiveClass.h"
#include "../../MemberFuncChecker/HaveSetActiveFuncChecker.h"

// 「setActive(bool)」を持っているクラスのリスト
class HaveSetActiveClassList
{
public:

	HaveSetActiveClassList() = default;

	// テンプレートメタを使用した「setActive(bool)」の所持判定＋追加
	template <class T, typename std::enable_if<HasSetActiveMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);
	template <class T, typename std::enable_if<!HasSetActiveMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	// 削除されたクラスをリストから削除する
	void removeExpandPtr();

	// 全てのリストの要素の「setActive(bool)」を呼ぶ
	void setActiveAll(bool isActive);

private:

	std::forward_list<HaveSetActiveClass> m_haveSetActiveClassList;
};

template<class T, typename std::enable_if<HasSetActiveMember<T>::value>::type*>
inline void HaveSetActiveClassList::checkAndAdd(std::weak_ptr<T> addClass)
{
	m_haveSetActiveClassList.push_front(HaveSetActiveClass(addClass));
}

template<class T, typename std::enable_if<!HasSetActiveMember<T>::value>::type*>
inline void HaveSetActiveClassList::checkAndAdd(std::weak_ptr<T> addClass)
{
	/* not have setActive() */
}