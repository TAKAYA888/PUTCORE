#pragma once

#include <memory>
#include <forward_list>
#include <TktkSafetyVoidSmartPtr/SafetyVoidSmartPtr.h>

#include "ProcessingClassMetaFunc/AwakeRunner.h"

#include "ProcessingClassList/ProcessingClass/ProcessingClass.h"
#include "ProcessingClassList/ProcessingClassList.h"

#include "UpdatableClassList/UpdatableClassList.h"
#include "DrawableClassList/DrawableClassList.h"
#include "CollidableClassList/CollidableClassList.h"
#include "AfterCollidableClassList/AfterCollidableClassList.h"
#include "MessageableClassList/MessageableClassList.h"
#include "DeletableClassList/DeletableClassList.h"
#include "ActiveCheckableClassList/ActiveCheckableClassList.h"

#include "StartableClassList/StartableClassList.h"
#include "OnEnableableClassList/OnEnableableClassList.h"
#include "OnDisableableClassList/OnDisableableClassList.h"
#include "OnDestroyableClassList/OnDestroyableClassList.h"

class ClassFuncProcessor
{
public:

	static void update();

	static void draw();

	static void finalize();
	
	template<class T>
	static void addClass(float drawPriority, int collisionGroupType, std::shared_ptr<T> addClass);
	
	template<class T>
	static void removeClass(std::weak_ptr<T> removeClass);
	
	template <class T, template<class U, class A = std::allocator<U>> class Container>
	static void removeClassAll(Container<std::weak_ptr<T>> removeClassContainer);
	
	template<class T>
	static std::weak_ptr<T> findClass();
	
	template <class T, template<class U, class A = std::allocator<U>> class Container>
	static Container<std::weak_ptr<T>> findClassAll();
	
	static void sendMessage(int eventMessageType, SafetyVoidSmartPtr<std::weak_ptr> param = std::weak_ptr<void>());
	
	template <class T>
	static void addUpdatePriority(float priority);
	
	static void addCollisionGroup(int type);
	
	static void addCollisionGroupPair(int groupOne, int groupTwo);

private:

	static ProcessingClassList m_mainList;

	static UpdatableClassList m_updatableList;
	static DrawableClassList m_drawableList;
	static CollidableClassList m_collidableList;
	static AfterCollidableClassList m_AfterCollidableList;
	static MessageableClassList m_messageableList;
	static DeletableClassList m_deletableList;
	static ActiveCheckableClassList m_activeCheckableList;

	static StartableClassList m_startableList;
	static OnEnableableClassList m_onEnableableList;
	static OnDisableableClassList m_onDisableableList;
	static OnDestroyableClassList m_onDestroyableList;
};

template<class T>
inline void ClassFuncProcessor::addClass(float drawPriority, int collisionGroupType, std::shared_ptr<T> addClass)
{
	auto processingClassPtr = std::make_shared<ProcessingClass>(addClass);

	m_mainList.add(processingClassPtr);
	m_updatableList.add<T>(processingClassPtr);

	m_drawableList.add<T>(drawPriority, processingClassPtr);
	m_collidableList.add<T>(collisionGroupType, processingClassPtr);
	m_AfterCollidableList.add<T>(processingClassPtr);
	m_messageableList.add<T>(processingClassPtr);
	m_deletableList.add<T>(processingClassPtr);
	m_activeCheckableList.add<T>(processingClassPtr);

	m_startableList.add<T>(processingClassPtr);
	m_onEnableableList.add<T>(processingClassPtr);
	m_onDisableableList.add<T>(processingClassPtr);
	m_onDestroyableList.add<T>(processingClassPtr);

	AwakeRunner::checkToRun(addClass);
}

template<class T>
inline void ClassFuncProcessor::removeClass(std::weak_ptr<T> removeClass)
{
	m_mainList.remove(removeClass);
}

template<class T, template<class U, class A = std::allocator<U>> class Container>
inline void ClassFuncProcessor::removeClassAll(Container<std::weak_ptr<T>> removeClassContainer)
{
	m_mainList.removeAll(removeClassContainer);
}

template<class T>
inline std::weak_ptr<T> ClassFuncProcessor::findClass()
{
	return m_mainList.find<T>();
}

template<class T, template<class U, class A = std::allocator<U>> class Container>
inline Container<std::weak_ptr<T>> ClassFuncProcessor::findClassAll()
{
	return m_mainList.findAll<T, Container>();
}

template<class T>
inline void ClassFuncProcessor::addUpdatePriority(float priority)
{
	m_updatableList.addPriority<T>(priority);
	m_AfterCollidableList.addPriority<T>(priority);
}