#include "AudioManager.h"

namespace AudioManager
{
	int volume = 128;
	void SetVolume(int newVolume)
	{
		volume = Math::Clamp(newVolume,0 , 128);
		Mix_VolumeMusic(volume);
		Debug::Log("Volume Set to: " + std::to_string(volume));
	}

	int GetVolume() { return volume; }

	void PlayClip(Mix_Chunk* chunk)
	{
		Mix_VolumeChunk(chunk, volume);
		Mix_PlayChannel(-1, chunk, 0);
	}

	void PlayMusic(Mix_Music* music)
	{
		Mix_VolumeMusic(volume);
		Mix_PlayMusic(music, 999);
	}

	void StopMusic() { Mix_PauseMusic(); }

	void ResumeMusic() { Mix_ResumeMusic(); }
}