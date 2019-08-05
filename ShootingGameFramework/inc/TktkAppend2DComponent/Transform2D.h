#ifndef TRANSFORM_2D_H_
#define TRANSFORM_2D_H_

#include <TktkMath/Matrix3.h>
#include <TktkMath/Vector2.h>
#include <TktkComponentFramework/Component/ComponentBase.h>

// 自身の座標、回転、スケールを管理するコンポーネント
class Transform2D
	: public ComponentBase
{
public:

	// 親のTransform2Dとの関係性の種類
	enum TraceParentType
	{
		// 親の座標のみを参照する
		TRACE_PARENT_POS					= 1 << 0,

		// 親のスケールのみを参照する
		TRACE_PARENT_SCALE					= 1 << 1,

		// 親の回転のみを参照する
		TRACE_PARENT_ROTATION				= 1 << 2,

		// 親のTransform2Dを参照しない
		NOT_TRACE_PARENT					= 0,

		// 親の座標とスケールを参照する
		TRACE_PARENT_POS_AND_SCALE			= TRACE_PARENT_POS | TRACE_PARENT_SCALE,

		// 親の座標と回転を参照する
		TRACE_PARENT_POS_AND_ROTATION		= TRACE_PARENT_POS | TRACE_PARENT_ROTATION,

		// 親のスケールと回転を参照する
		TRACE_PARENT_SCALE_AND_ROTATION		= TRACE_PARENT_SCALE | TRACE_PARENT_ROTATION,

		// 親のTransform2Dを完全に参照する
		TRACE_PARENT_ALL					= TRACE_PARENT_POS | TRACE_PARENT_SCALE | TRACE_PARENT_ROTATION,
	};

public:

	// std::shared_ptr<Transform2D>を生成する
	static std::shared_ptr<Transform2D> create(
		const Vector2& initPosition,					// 初期座標
		const Vector2& initScaleRate,					// 初期スケール
		float initRotationDeg,							// 初期回転
		TraceParentType traceType = TRACE_PARENT_ALL	// 親のTransform2Dとの関係性の種類
	);

public:

	Transform2D(
		const Vector2& initPosition,					// 初期座標
		const Vector2& initScaleRate,					// 初期スケール
		float initRotationDeg,							// 初期回転
		TraceParentType traceType = TRACE_PARENT_ALL	// 親のTransform2Dとの関係性の種類
	);

public:

	// ワールドの行列を取得
	const Matrix3& getPose() const;

	// ワールド座標を取得
	Vector2 getWorldPosition() const;
	// ワールドスケールを取得
	Vector2 getWorldScaleRate() const;
	// ワールド回転を取得
	float getWorldRotationDeg() const;

	// ローカル座標を取得
	const Vector2& getLocalPosition() const;
	// ローカルスケールを取得
	const Vector2& getLocalScaleRate() const;
	// ローカル回転を取得
	float getLocalRotationDeg() const;

	// ローカル座標を設定
	void setLocalPosition(const Vector2& position);
	// ローカルスケールを設定
	void setLocalScaleRate(const Vector2& scaleRate);
	// ローカル回転を設定
	void setLocalRotationDeg(float rotationDeg);

	// 行列の再計算
	void reCalculateMatrix();

public:

	// <PolymorphismFunc>
	void start();
	void update();
	void afterCollide();

private:

	// 行列計算
	void calculateMatrix();

	// 親のTransform2Dを取得
	std::weak_ptr<Transform2D> findParentTransform2D(GameObjectPtr parent);

private:

	bool m_preFlameTransformParent{ false };

	Vector2 m_localPosition;
	Vector2 m_localScaleRate;
	float m_localRotationDeg;

	Matrix3 m_localMatrix;
	Matrix3 m_worldMatrix;
	Matrix3 m_parentMatrix;

	TraceParentType m_traceType;
};
#endif // !TRANSFORM_2D_H_