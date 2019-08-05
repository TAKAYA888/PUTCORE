#pragma once

#include <type_traits>
#include "../../GameObject/GameObjectPtr.h"

struct HasSetGameObjectMemberImpl
{
	template <class T>
	static auto check(T*) ->decltype(
		std::declval<T>()->setGameObject(std::declval<GameObjectPtr>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasSetGameObjectMember : decltype (HasSetGameObjectMemberImpl::check<T>(nullptr)) {};

struct ComponentUserSetter
{
	template <class T, typename std::enable_if<HasSetGameObjectMember<T>::value>::type* = nullptr>
	static void checkToSet(T& component, GameObjectPtr gameObject)
	{
		component->setGameObject(gameObject);
	}

	template <class T, typename std::enable_if<!HasSetGameObjectMember<T>::value>::type* = nullptr>
	static void checkToSet(T& notComponent, GameObjectPtr gameObject)
	{
		/* not component */
	}
};