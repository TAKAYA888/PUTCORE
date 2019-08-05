#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "HaveCollisionExitComponent.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"
#include "../../../GameObject/GameObjectPtr.h"

class HaveCollisionExitComponentList
{
public:

	HaveCollisionExitComponentList() = default;

	template <class T, typename std::enable_if<HasCollisionExitMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	template <class T, typename std::enable_if<!HasCollisionExitMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	void removeExpandPtr();

	void onCollisionExitAll(GameObjectPtr other);

private:

	std::forward_list<HaveCollisionExitComponent> m_haveCollisionExitComponentList;
};

template<class T, typename std::enable_if<HasCollisionExitMember<T>::value>::type*>
inline void HaveCollisionExitComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	m_haveCollisionExitComponentList.push_front(HaveCollisionExitComponent(addClass));
}

template<class T, typename std::enable_if<!HasCollisionExitMember<T>::value>::type*>
inline void HaveCollisionExitComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	/* not have onCollisionExit() */
}