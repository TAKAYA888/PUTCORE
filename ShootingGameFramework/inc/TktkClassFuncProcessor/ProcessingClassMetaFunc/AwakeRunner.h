#pragma once

#include <type_traits>

struct HasAwakeMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>()->awake(),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasAwakeMember : decltype(HasAwakeMemberImpl::check<T>(nullptr))
{
};

struct AwakeRunner
{
	template <class T, typename std::enable_if<HasAwakeMember<T>::value>::type* = nullptr>
	static void checkToRun(T& runClass)
	{
		runClass->awake();
	}

	template <class T, typename std::enable_if<!HasAwakeMember<T>::value>::type* = nullptr>
	static void checkToRun(T& runClass)
	{
		/* not have awake() */
	}
};