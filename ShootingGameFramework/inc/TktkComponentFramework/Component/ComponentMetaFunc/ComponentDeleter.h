#pragma once

#include <type_traits>

struct HasDestroyMemberImpl
{
	template <class T>
	static auto check(T*) ->decltype(
		std::declval<T>()->destroy(),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

template <class T>
struct HasDestroyMember : decltype (HasDestroyMemberImpl::check<T>(nullptr)) {};

struct ComponentDeleter
{
	template <class T, typename std::enable_if<HasDestroyMember<T>::value>::type* = nullptr>
	static void checkToDestroy(T& component)
	{
		component->destroy();
	}

	template <class T, typename std::enable_if<!HasDestroyMember<T>::value>::type* = nullptr>
	static void checkToDestroy(T& notComponent)
	{
		/* not component */
	}
};