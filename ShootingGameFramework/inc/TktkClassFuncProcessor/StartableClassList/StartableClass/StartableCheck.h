#pragma once

#include <type_traits>

struct HasStartMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->start(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasStartMember : decltype(HasStartMemberImpl::check<T>(nullptr))
{
};