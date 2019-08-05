#pragma once

#include <forward_list>
#include <TktkMath/Vector2.h>
#include <Tktk2dCollision/Body2dBase/Body2dBase.h>
#include <Tktk2dCollision/BoundingPolygon2d.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// �����`�̓����蔻��̃R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class RectCollider
	: public ComponentBase
{
public:

	// std::shared_ptr<RectCollider>�𐶐�����
	static std::shared_ptr<RectCollider> create(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		const Vector2& rectSize,						// �����蔻��̑傫��
		const Vector2& localPosition = Vector2::zero	// �����蔻��̃��[�J�����W
	);

public:

	RectCollider(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		const Vector2& rectSize,						// �����蔻��̑傫��
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

	HitInfo2D m_hitInfo;

	BoundingPolygon2d m_boundingPolygon2d;

	std::weak_ptr<Transform2D> m_transform2D;
};