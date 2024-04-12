#include "MusicSource.h"

MusicSource::MusicSource()
{
}

MusicSource::~MusicSource()
{

}

void MusicSource::SetMusicClip(const char* clipName)
{
	_musicClip = entity->scene->engine->assetWarehouse->GetMusic(clipName);

	if (_musicClip == nullptr)
	{
		std::string name = clipName;
		Debug::LogError("MusicSource couldn't find " + name + ". This MusicSource will not do anything! ", this);
	}
}

void MusicSource::Play()
{
	if (_musicClip == nullptr) return;

	// Have the audio mixer automatically choose the
	// channel it should play on. Give it the clip,
	// and we dont want it to repeat. so set it to 0.
	AudioManager::PlayMusic(_musicClip);
}

void MusicSource::Play(const char* clipName)
{
	SetMusicClip(clipName);

	if (_musicClip == nullptr) return;

	// Have the audio mixer automatically choose the
	// channel it should play on. Give it the clip,
	// and we dont want it to repeat. so set it to 0.
	AudioManager::PlayMusic(_musicClip);
}
