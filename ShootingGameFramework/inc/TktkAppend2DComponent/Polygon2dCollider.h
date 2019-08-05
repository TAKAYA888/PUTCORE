#pragma once

#include <vector>
#include <forward_list>
#include <TktkMath/Vector2.h>
#include <Tktk2dCollision/Body2dBase/Body2dBase.h>
#include <Tktk2dCollision/BoundingPolygon2d.h>
#include <TktkComponentFramework/Component/ComponentBase.h>
#include "TktkAppend2DComponent/Transform2D.h"

// ���p�`�̓����蔻��̃R���|�[�l���g
// �y�O��R���|�[�l���g�FTransform2D�z
class Polygon2dCollider
	: public ComponentBase
{
public:

	// std::shared_ptr<Polygon2dCollider>�𐶐�����
	static std::shared_ptr<Polygon2dCollider> create(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		const std::vector<Vector2>& vertexs,			// �����蔻����\�����钸�_�̍��W�i���v���j
		const Vector2& localPosition = Vector2::zero	// �����蔻��̃��[�J�����W
	);

public:

	Polygon2dCollider(
		int collisionGroupType,							// �����蔻��̃O���[�v�ԍ�
		const std::vector<Vector2>& vertexs,			// �����蔻����\�����钸�_�̍��W�i���v���j
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