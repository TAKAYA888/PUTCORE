#pragma once

#include <type_traits>

struct HasOnDestroyMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->onDestroy(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasOnDestroyMember : decltype(HasOnDestroyMemberImpl::check<T>(nullptr))
{
};