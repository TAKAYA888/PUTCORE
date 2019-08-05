#pragma once

#include <type_traits>

struct HasOnEnableMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->onEnable(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasOnEnableMember : decltype(HasOnEnableMemberImpl::check<T>(nullptr))
{
};