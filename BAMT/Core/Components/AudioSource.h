#ifndef BAMT_AUDIO_SOURCE
#define BAMT_AUDIO_SOURCE

#include "Component.h"
#include "EngineManager.h"
#include "SDL_mixer.h"

class AudioSource : public Component
{
	Mix_Chunk* _audioClip = nullptr;

	public:
		AudioSource();
		AudioSource(const char* clipName);
		~AudioSource() override;

		void SetAudioClip(const char* clipName);
		void Play();
		void Play(const char* clipName);
};
#endif