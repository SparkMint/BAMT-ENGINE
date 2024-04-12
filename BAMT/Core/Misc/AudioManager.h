#ifndef BAMT_AUDIO_MANAGER
#define BAMT_AUDIO_MANAGER

#include "SDL_mixer.h"
#include "EngineManager.h"
#include "BamtMath.h"

/// <summary>
/// The AudioManager is responsible for keeping track of the volume of audio.
/// And it plays audioclips.
/// </summary>
namespace AudioManager
{
	void SetVolume(int newVolume);
	int GetVolume();

	void PlayClip(Mix_Chunk* chunk);
	void PlayMusic(Mix_Music* music);
	void StopMusic();
	void ResumeMusic();
}
#endif