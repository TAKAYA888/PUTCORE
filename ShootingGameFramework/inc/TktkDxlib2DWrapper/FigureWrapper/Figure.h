#ifndef RECT_H_
#define RECT_H_

#include <vector>
#include <TktkMath/Color.h>
#include <TktkMath/Vector2.h>

class Figure
{
public:

	static void drawLine(
		const Vector2& firstPos,
		const Vector2& secondPos,
		float lineThickness,
		const Color& color,
		bool useAntialiasing
	);

	static void drawRect(
		const Vector2& leftTop,
		const Vector2& rightBottom,
		float lineThickness,
		const Color& color,
		bool isFill,
		bool useAntialiasing
	);

	// ※アンチエイリアスを無効にすると線の太さの指定ができなくなる
	static void drawTriangle(
		const Vector2& firstPos,
		const Vector2& secondPos,
		const Vector2& thirdPos,
		float lineThickness,
		const Color& color,
		bool isFill,
		bool useAntialiasing
	);

	static void drawCircle(
		const Vector2& centerPos,
		float radius,
		float lineThickness,
		const Color& color,
		bool isFill
	);

	static void drawOval(
		const Vector2& centerPos,
		const Vector2& radius,
		float lineThickness,
		const Color& color,
		bool isFill
	);

	static void drawRegularPolygon(
		const Vector2& centerPos,
		float radius,
		int vertexNum,
		float lineThickness,
		const Color& color,
		bool isFill
	);

	static void drawSymmetricalPolygon(
		const Vector2& centerPos,
		const Vector2& radius,
		int vertexNum,
		float lineThickness,
		const Color& color,
		bool isFill
	);

	static void drawPolygon(
		const std::vector<Vector2>& vertexs,
		float lineThickness,
		const Color& color,
		bool isFill,
		bool useAntialiasing
	);
};

#endif // !RECT_H_