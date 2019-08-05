#pragma once

#include <typeindex>
#include <memory>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

class ProcessingClass
{
public:

	template<class U>
	ProcessingClass(std::shared_ptr<U> other);

	template<class U>
	bool isSame(std::weak_ptr<U> other) const;

	template<class U>
	bool canCast() const;

	template<class U>
	std::weak_ptr<U> castPtr() const;

	std::weak_ptr<void> rawPtr() const;

	std::type_index typeIndex() const;

	bool isDestroy() const;
	bool isActive() const;

	void destroy();
	void setActive(bool isActive);

private:

	bool m_isDestroy{ false };

	bool m_isActive{ false };

	SafetyVoidSmartPtr<std::shared_ptr> m_voidPtr;
};

template<class U>
inline ProcessingClass::ProcessingClass(std::shared_ptr<U> other)
	: m_voidPtr(other)
{
}

template<class U>
inline bool ProcessingClass::isSame(std::weak_ptr<U> other) const
{
	if (other.expired()) return false;

	return m_voidPtr.isSame(other.lock());
}

template<class U>
inline bool ProcessingClass::canCast() const
{
	return m_voidPtr.canCast<U>();
}

template<class U>
inline std::weak_ptr<U> ProcessingClass::castPtr() const
{
	return m_voidPtr.castPtr<U>();
}