#ifndef COLOR_H_
#define COLOR_H_

#include <ostream>
#include <string>

struct Color
{
	float r, g, b, a;

	Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f);

	// �t�H�[�}�b�g���ꂽ������ɕϊ�
	std::string toString() const;

	// 2�̃J���[�Ԃ̐��`��Ԃ��s���܂�
	static Color lerp(const Color& value1, const Color& value2, float amount);

	// ��v����e�����y�A�̍ł��Ⴂ�l���܂ރJ���[��Ԃ��܂�
	static Color calculateMin(const Color& value1, const Color& value2);

	// ��v����e�����y�A�̍ł������l���܂ރJ���[��Ԃ��܂�
	static Color calculateMax(const Color& value1, const Color& value2);

	//	�l���w�肳�ꂽ�͈͓��ɐ������܂�
	static Color clamp(const Color& value1, const Color& min = Color(0.0f, 0.0f, 0.0f, 0.0f), const Color& max = Color(1.0f, 1.0f, 1.0f, 1.0f));

	// Color(0, 0, 0, 1)
	static const Color black;

	// Color(1, 1, 1, 1)
	static const Color white;

	// Color(1, 0, 0, 1)
	static const Color red;

	// Color(0, 1, 0, 1)
	static const Color green;

	// Color(0, 0, 1, 1)
	static const Color blue;
};

Color& operator += (Color& c1, const Color& c2);
Color& operator -= (Color& c1, const Color& c2);
Color& operator *= (Color& c1, const Color& c2);
Color& operator *= (Color& c, float s);
Color& operator /= (Color& c, float s);

Color operator + (Color c1, const Color& c2);
Color operator - (Color c1, const Color& c2);
Color operator * (Color c1, const Color& c2);
Color operator * (Color c, float s);
Color operator * (float s, Color c);
Color operator / (Color c, float s);

std::ostream& operator<<(std::ostream& os, const Color& color);

#endif