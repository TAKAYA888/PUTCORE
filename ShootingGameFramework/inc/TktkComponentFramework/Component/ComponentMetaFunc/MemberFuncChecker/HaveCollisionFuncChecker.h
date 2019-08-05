#pragma once

#include <type_traits>
#include "../../../GameObject/GameObjectPtr.h"

struct HasCollisionEnterMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>().onCollisionEnter(std::declval<GameObjectPtr>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasCollisionEnterMember : decltype(HasCollisionEnterMemberImpl::check<T>(nullptr))
{
};

struct HasCollisionStayMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>().onCollisionStay(std::declval<GameObjectPtr>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasCollisionStayMember : decltype(HasCollisionStayMemberImpl::check<T>(nullptr))
{
};

struct HasCollisionExitMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>().onCollisionExit(std::declval<GameObjectPtr>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasCollisionExitMember : decltype(HasCollisionExitMemberImpl::check<T>(nullptr))
{
};