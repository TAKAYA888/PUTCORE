#pragma once

#include <type_traits>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

struct HasIsCollideMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->isCollide(std::declval<const SafetyVoidSmartPtr<std::weak_ptr>>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasIsCollideMember : decltype(HasIsCollideMemberImpl::check<T>(nullptr))
{
};

struct HasOnCollideMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->onCollide(std::declval<SafetyVoidSmartPtr<std::weak_ptr>>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasOnCollideMember : decltype(HasOnCollideMemberImpl::check<T>(nullptr))
{
};