#pragma once

#include <memory>
#include <forward_list>
#include "HaveSetActiveClass.h"
#include "../../MemberFuncChecker/HaveSetActiveFuncChecker.h"

// �usetActive(bool)�v�������Ă���N���X�̃��X�g
class HaveSetActiveClassList
{
public:

	HaveSetActiveClassList() = default;

	// �e���v���[�g���^���g�p�����usetActive(bool)�v�̏�������{�ǉ�
	template <class T, typename std::enable_if<HasSetActiveMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);
	template <class T, typename std::enable_if<!HasSetActiveMember<T>::value>::type* = nullptr>
	void checkAndAdd(std::weak_ptr<T> addClass);

	// �폜���ꂽ�N���X�����X�g����폜����
	void removeExpandPtr();

	// �S�Ẵ��X�g�̗v�f�́usetActive(bool)�v���Ă�
	void setActiveAll(bool isActive);

private:

	std::forward_list<HaveSetActiveClass> m_haveSetActiveClassList;
};

template<class T, typename std::enable_if<HasSetActiveMember<T>::value>::type*>
inline void HaveSetActiveClassList::checkAndAdd(std::weak_ptr<T> addClass)
{
	m_haveSetActiveClassList.push_front(HaveSetActiveClass(addClass));
}

template<class T, typename std::enable_if<!HasSetActiveMember<T>::value>::type*>
inline void HaveSetActiveClassList::checkAndAdd(std::weak_ptr<T> addClass)
{
	/* not have setActive() */
}