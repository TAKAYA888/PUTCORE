#pragma once

#include <type_traits>

struct HasIsDestroyMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->isDestroy(), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasIsDestroyMember : decltype(HasIsDestroyMemberImpl::check<T>(nullptr))
{
};