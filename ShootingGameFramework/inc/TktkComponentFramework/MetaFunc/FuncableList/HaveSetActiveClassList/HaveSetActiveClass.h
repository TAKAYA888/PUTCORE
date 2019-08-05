#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../../MemberFuncChecker/HaveSetActiveFuncChecker.h"

// �usetActive(bool)�v�������Ă���Ǝv����N���X�̃|�C���^�����b�v����N���X
class HaveSetActiveClass
{
public:

	template <class T>
	HaveSetActiveClass(std::weak_ptr<T> haveSetActiveClass);

	// ���b�v�����N���X���usetActive(bool)�v�������Ă�������s����
	void setActive(bool isActive);

	bool expiredPtr() const;

private:

	// �O����B���e���v���[�g�N���X�́usetActive(bool)�v���s�֐��|�C���^
	struct VTable
	{
		void(*setActive)(SafetyVoidSmartPtr<std::weak_ptr>, bool isActive);
	};

	// �\����͉B�����e���v���[�g�N���X
	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		// �usetActive(bool)�v�������Ă�������s����
		static void setActive(SafetyVoidSmartPtr<std::weak_ptr> self, bool isActive);

		// �e���v���[�g���^���g�p�����usetActive(bool)�v�̏������聕���s(�����Ă���ꍇ)
		template <class T, typename std::enable_if<HasSetActiveMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, bool isActive)
		{
			runClass.lock()->setActive(isActive);
		}

		// �e���v���[�g���^���g�p�����usetActive(bool)�v�̏������聕���s(�����Ă��Ȃ��ꍇ)
		template <class T, typename std::enable_if<!HasSetActiveMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, bool isActive)
		{
			/* not have onCollisionEnter() */
		}
	};

private:

	SafetyVoidSmartPtr<std::weak_ptr> m_this;

	VTable* m_vtablePtr;
};

template<class T>
inline HaveSetActiveClass::HaveSetActiveClass(std::weak_ptr<T> other)
	: m_this(other)
	, m_vtablePtr(&VTableInitializer<T>::m_vtable)
{
}

template <class T>
HaveSetActiveClass::VTable HaveSetActiveClass::VTableInitializer<T>::m_vtable =
{
	&HaveSetActiveClass::VTableInitializer<T>::setActive
};

template <class T>
inline void HaveSetActiveClass::VTableInitializer<T>::setActive(SafetyVoidSmartPtr<std::weak_ptr> self, bool isActive)
{
	checkAndRun(self.castPtr<T>(), isActive);
}