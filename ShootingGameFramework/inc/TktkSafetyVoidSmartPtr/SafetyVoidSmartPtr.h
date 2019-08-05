#pragma once

#include <memory>
#include <typeindex>

// キャストミスの危険性を排除したvoidスマートポインタクラス
template <template<class T> class smart_ptr = std::shared_ptr>
class SafetyVoidSmartPtr
{
public:

	SafetyVoidSmartPtr(smart_ptr<void> other, std::type_index typeIndex)
		: m_this(other)
		, m_typeIndex(typeIndex)
	{
	}

	template<class U>
	SafetyVoidSmartPtr(smart_ptr<U> other);

	// 引数のポインタと自身のポインタが等しいか？
	template<class U>
	bool isSame(smart_ptr<U> other) const;

	// スマートポインタを取得
	smart_ptr<void> voidPtr() const;

	// タイプインデックスを取得
	std::type_index typeIndex() const;

	// テンプレートパラメーターのクラスにキャストできるか？
	template<class U>
	bool canCast() const;

	// テンプレートパラメーターのクラスのスマートポインタにキャストする
	template<class U>
	smart_ptr<U> castPtr() const;

private:

	smart_ptr<void> m_this;

	std::type_index m_typeIndex;
};

template<template<class T> class smart_ptr>
template<class U>
inline SafetyVoidSmartPtr<smart_ptr>::SafetyVoidSmartPtr(smart_ptr<U> other)
	: m_this(other)
	, m_typeIndex(typeid(U))
{
}

template<>
template<class U>
inline bool SafetyVoidSmartPtr<std::shared_ptr>::isSame(std::shared_ptr<U> other) const
{
	return (other == m_this);
}

template<>
template<class U>
inline bool SafetyVoidSmartPtr<std::weak_ptr>::isSame(std::weak_ptr<U> other) const
{
	if (other.expired() && m_this.expired()) return true;

	if (other.expired() || m_this.expired()) return false;

	return (other.lock() == m_this.lock());
}

template<template<class T> class smart_ptr>
inline smart_ptr<void> SafetyVoidSmartPtr<smart_ptr>::voidPtr() const
{
	return m_this;
}

template<template<class T> class smart_ptr>
inline std::type_index SafetyVoidSmartPtr<smart_ptr>::typeIndex() const
{
	return m_typeIndex;
}

template<template<class T> class smart_ptr>
template<class U>
inline bool SafetyVoidSmartPtr<smart_ptr>::canCast() const
{
	return (m_typeIndex == typeid(U));
}

template<>
template<class U>
inline std::shared_ptr<U> SafetyVoidSmartPtr<std::shared_ptr>::castPtr() const
{
	if (canCast<U>()) return std::reinterpret_pointer_cast<U>(m_this);
	return std::shared_ptr<U>();
}

template<>
template<class U>
inline std::weak_ptr<U> SafetyVoidSmartPtr<std::weak_ptr>::castPtr() const
{
	if (canCast<U>() && !m_this.expired()) return std::reinterpret_pointer_cast<U>(m_this.lock());
	return std::weak_ptr<U>();
}