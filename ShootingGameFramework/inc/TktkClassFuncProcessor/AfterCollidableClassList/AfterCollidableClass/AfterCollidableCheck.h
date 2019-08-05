#pragma once

#include <type_traits>

struct HasAfterCollideMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->afterCollide(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasAfterCollideMember : decltype(HasAfterCollideMemberImpl::check<T>(nullptr))
{
};