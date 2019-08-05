#pragma once

#include <type_traits>

struct HasOnDisableMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->onDisable(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasOnDisableMember : decltype(HasOnDisableMemberImpl::check<T>(nullptr))
{
};