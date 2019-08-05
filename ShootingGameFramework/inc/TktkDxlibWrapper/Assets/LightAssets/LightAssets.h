#ifndef LIGHT_ASSETS_H_
#define LIGHT_ASSETS_H_

#include <unordered_map>
#include <TktkMath/Vector3.h>
#include <TktkMath/Color.h>

class LightAssets
{
public:

	static void initialize();

	static void finalize();

	static void createDirectionalLight(
		int id,
		const Vector3& direction,
		const Color& diffuse,
		const Color& specular,
		const Color& ambient
	);

	static void createPointLight(
		int id,
		const Vector3& position,
		float range,
		const float attenuation[3],
		const Color& diffuse,
		const Color& specular,
		const Color& ambient
	);

	static void createSpotLight(
		int id,
		const Vector3& position,
		const Vector3& direction,
		float outAngleDegree,
		float inAngleDegree,
		float range,
		const float attenuation[3],
		const Color& diffuse,
		const Color& specular,
		const Color& ambient
	);

	static void erase(int id);

	static void eraseAll();

	static const int& getLight(int id);

private:

	static std::unordered_map<int, int> m_assets;
};

#endif // !LIGHT_ASSETS_H_