#pragma once

#include <type_traits>
#include "../../GameObject/GameObjectPtr.h"

struct HasGetCollisionGroupTypeMemberImpl
{
	template <class T>
	static auto check(T*) ->decltype(
		std::declval<T>()->getCollisionGroupType(),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasGetCollisionGroupTypeMember : decltype (HasGetCollisionGroupTypeMemberImpl::check<T>(nullptr)) {};

struct ComponentCollisionGroupGetter
{
	template <class T, typename std::enable_if<HasGetCollisionGroupTypeMember<T>::value>::type* = nullptr>
	static int checkToGet(T& component)
	{
		return component->getCollisionGroupType();
	}

	template <class T, typename std::enable_if<!HasGetCollisionGroupTypeMember<T>::value>::type* = nullptr>
	static int checkToGet(T& notComponent)
	{
		return 0;
		/* not component */
	}
};