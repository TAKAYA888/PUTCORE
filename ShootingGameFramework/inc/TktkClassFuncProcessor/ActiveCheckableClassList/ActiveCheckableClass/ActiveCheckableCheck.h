#pragma once

#include <type_traits>

struct HasIsActiveMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->isActive(),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasIsActiveMember : decltype(HasIsActiveMemberImpl::check<T>(nullptr))
{
};