#pragma once

#include <type_traits>

struct HasDrawMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->draw(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasDrawMember : decltype(HasDrawMemberImpl::check<T>(nullptr))
{
};