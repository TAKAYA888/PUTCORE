#pragma once

#include <type_traits>

struct HasUpdateMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->update(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasUpdateMember : decltype(HasUpdateMemberImpl::check<T>(nullptr))
{
};