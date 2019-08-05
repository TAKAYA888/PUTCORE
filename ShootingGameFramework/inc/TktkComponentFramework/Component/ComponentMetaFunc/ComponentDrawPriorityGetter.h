#pragma once //ComponentDrawPriorityGetter

#include <type_traits>
#include "../../GameObject/GameObjectPtr.h"

struct HasGetDrawPriorityMemberImpl
{
	template <class T>
	static auto check(T*) ->decltype(
		std::declval<T>()->getDrawPriority(),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasGetDrawPriorityMember : decltype (HasGetDrawPriorityMemberImpl::check<T>(nullptr)) {};

struct ComponentDrawPriorityGetter
{
	template <class T, typename std::enable_if<HasGetDrawPriorityMember<T>::value>::type* = nullptr>
	static float checkToGet(T& component)
	{
		return component->getDrawPriority();
	}

	template <class T, typename std::enable_if<!HasGetDrawPriorityMember<T>::value>::type* = nullptr>
	static float checkToGet(T& notComponent)
	{
		return 0;
		/* not component */
	}
};