#pragma once

#include <forward_list>
#include <TktkMath/Vector2.h>
#include <Tktk2dCollision/Body2dBase/Body2dBase.h>
#include <Tktk2dCollision/BoundingCircle.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// �^�~�̓����蔻��̃R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class CircleCollider
	: public ComponentBase
{
public:

	// std::shared_ptr<CircleCollider>�𐶐�����
	static std::shared_ptr<CircleCollider> create(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		float radius,									// �����蔻��̔��a
		const Vector2& localPosition = Vector2::zero	// �����蔻��̃��[�J�����W
	);

public:

	CircleCollider(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		float radius,									// �����蔻��̔��a
		const Vector2& localPosition = Vector2::zero	// �����蔻��̃��[�J�����W
	);

public:

	// <PolymorphismFunc>
	void update();
	bool isCollide(const SafetyVoidSmartPtr<std::weak_ptr> other);
	void onCollide(SafetyVoidSmartPtr<std::weak_ptr> other);
	void afterCollide();

public:

	// �����蔻��̃N���X���擾
	const Body2dBase& getBodyBase() const;

private:

	std::forward_list<GameObjectPtr> m_curHitObjectList;
	std::forward_list<GameObjectPtr> m_preHitObjectList;

	bool m_curIsCollide{ false };
	bool m_preIsCollide{ false };

	HitInfo2D m_hitInfo;

	BoundingCircle m_boundingCircle;

	std::weak_ptr<Transform2D> m_transform2D;
};