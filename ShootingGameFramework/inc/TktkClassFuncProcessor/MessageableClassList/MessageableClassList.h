#pragma once

#include <memory>
#include <typeindex>
#include <forward_list>
#include <unordered_map>
#include "MessageableClass/MessageableClass.h"

class MessageableClassList
{
public:

	MessageableClassList() = default;

	template <class T>
	void add(std::weak_ptr<ProcessingClass> addClass, T* = nullptr);

	void addNewClass();

	void removeExpandPtr();

	void handleMessageAll(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param);

private:

	std::forward_list<MessageableClass> m_messageableClassList;

	std::forward_list<MessageableClass> m_addClassList;
};

template<class T>
inline void MessageableClassList::add(std::weak_ptr<ProcessingClass> addClass, T* ptr)
{
	m_addClassList.push_front(MessageableClass(addClass, ptr));
}