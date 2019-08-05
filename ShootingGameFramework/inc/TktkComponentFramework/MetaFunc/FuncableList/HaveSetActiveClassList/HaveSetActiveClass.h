#pragma once

#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>
#include "../../MemberFuncChecker/HaveSetActiveFuncChecker.h"

// 「setActive(bool)」を持っていると思われるクラスのポインタをラップするクラス
class HaveSetActiveClass
{
public:

	template <class T>
	HaveSetActiveClass(std::weak_ptr<T> haveSetActiveClass);

	// ラップしたクラスが「setActive(bool)」を持っていたら実行する
	void setActive(bool isActive);

	bool expiredPtr() const;

private:

	// 外から隠すテンプレートクラスの「setActive(bool)」実行関数ポインタ
	struct VTable
	{
		void(*setActive)(SafetyVoidSmartPtr<std::weak_ptr>, bool isActive);
	};

	// 表からは隠されるテンプレートクラス
	template <class T>
	struct VTableInitializer
	{
		static VTable m_vtable;

		// 「setActive(bool)」を持っていたら実行する
		static void setActive(SafetyVoidSmartPtr<std::weak_ptr> self, bool isActive);

		// テンプレートメタを使用した「setActive(bool)」の所持判定＆実行(持っている場合)
		template <class T, typename std::enable_if<HasSetActiveMember<T>::value>::type* = nullptr>
		static void checkAndRun(std::weak_ptr<T> runClass, bool isActive)
		{
			runClass.lock()->setActive(isActive);
		}

		// テンプレートメタを使用した「setActive(bool)」の所持判定＆実行(持っていない場合)
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