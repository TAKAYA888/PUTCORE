#pragma once

#include <type_traits>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

struct HasHandleMessageMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->handleMessage(std::declval<int>(), std::declval<SafetyVoidSmartPtr<std::weak_ptr>>()), std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasHandleMessageMember : decltype(HasHandleMessageMemberImpl::check<T>(nullptr))
{
};