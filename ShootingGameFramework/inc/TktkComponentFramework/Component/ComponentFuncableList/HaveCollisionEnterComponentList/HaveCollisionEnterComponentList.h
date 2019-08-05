#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "HaveCollisionEnterComponent.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"
#include "../../../GameObject/GameObjectPtr.h"

class HaveCollisionEnterComponentList
{
public:

	HaveCollisionEnterComponentList() = default;

	template <class T, typename std::enable_if<HasCollisionEnterMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	template <class T, typename std::enable_if<!HasCollisionEnterMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	void removeExpandPtr();

	void onCollisionEnterAll(GameObjectPtr other);

private:

	std::forward_list<HaveCollisionEnterComponent> m_haveCollisionEnterComponentList;
};

template<class T, typename std::enable_if<HasCollisionEnterMember<T>::value>::type*>
inline void HaveCollisionEnterComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	m_haveCollisionEnterComponentList.push_front(HaveCollisionEnterComponent(addClass));
}

template<class T, typename std::enable_if<!HasCollisionEnterMember<T>::value>::type*>
inline void HaveCollisionEnterComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	/* not have onCollisionEnter() */
}