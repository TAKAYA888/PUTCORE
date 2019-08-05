#ifndef SOUND_H_
#define SOUND_H_

#include <string>
#include <unordered_map>

class Sound
{
public:

	static void initialize();

	static void loadBgm(int id, const std::string& fileName);

	static void playBgm(int id);

	static void stopBgm();

	static void deleteBgm(int id);

	static void loadSe(int id, const std::string& fileName);

	static void playSe(int id);

	static void deleteSe(int id);

	static void finalize();

private:

	static std::unordered_map<int, int> m_bgmMap;

	static int m_currentBgm;

	static std::unordered_map<int, int> m_seMap;
};

#endif // !SOUND_H_