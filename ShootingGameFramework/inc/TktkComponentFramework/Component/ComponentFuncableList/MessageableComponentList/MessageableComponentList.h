#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "MessageableComponent.h"

class MessageableComponentList
{
public:

	MessageableComponentList() = default;

	template <class T>
	void add(std::weak_ptr<T> addClass);

	void removeExpandPtr();

	void handleMessageAll(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	std::forward_list<MessageableComponent> m_messageableComponentList;
};

template<class T>
inline void MessageableComponentList::add(std::weak_ptr<T> addClass)
{
	m_messageableComponentList.push_front(MessageableComponent(addClass));
}