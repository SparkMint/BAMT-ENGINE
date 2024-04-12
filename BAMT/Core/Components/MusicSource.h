#ifndef BAMT_MUSIC_SOURCE
#define BAMT_MUSIC_SOURCE
#include "Component.h"
#include "EngineManager.h"
#include "SDL_mixer.h"

class MusicSource : public Component
{
	Mix_Music* _musicClip = nullptr;

public:
	MusicSource();
	~MusicSource() override;

	void SetMusicClip(const char* clipName);
	void Play();
	void Play(const char* clipName);
};

#endif

