#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include "HaveCollisionStayComponent.h"
#include "../../ComponentMetaFunc/MemberFuncChecker/HaveCollisionFuncChecker.h"
#include "../../../GameObject/GameObjectPtr.h"

class HaveCollisionStayComponentList
{
public:

	HaveCollisionStayComponentList() = default;

	template <class T, typename std::enable_if<HasCollisionStayMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	template <class T, typename std::enable_if<!HasCollisionStayMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	void removeExpandPtr();

	void onCollisionStayAll(GameObjectPtr other);

private:

	std::forward_list<HaveCollisionStayComponent> m_haveCollisionStayComponentList;
};

template<class T, typename std::enable_if<HasCollisionStayMember<T>::value>::type*>
inline void HaveCollisionStayComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	m_haveCollisionStayComponentList.push_front(HaveCollisionStayComponent(addClass));
}

template<class T, typename std::enable_if<!HasCollisionStayMember<T>::value>::type*>
inline void HaveCollisionStayComponentList::checkAndAdd(std::weak_ptr<T> addClass)
{
	/* not have onCollisionStay() */
}