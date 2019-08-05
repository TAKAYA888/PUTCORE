#pragma once

#include <type_traits>

struct HasSetActiveMemberImpl
{
	template <class T>
	static auto check(T*) -> decltype(
		std::declval<T&>().setActive(std::declval<bool>()),
		std::true_type()
		);

	template <class T>
	static auto check(...)->std::false_type;
};

// �e���v���[�g�p�����[�^�̃N���X���usetActive(bool)�v�������Ă��邩�̔���
template <class T>
struct HasSetActiveMember : decltype(HasSetActiveMemberImpl::check<T>(nullptr))
{
};