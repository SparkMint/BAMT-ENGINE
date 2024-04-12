#include "AudioSource.h"

AudioSource::AudioSource()
{
}

AudioSource::AudioSource(const char* clipName)
{
	SetAudioClip(clipName);
}

AudioSource::~AudioSource()
{
}

void AudioSource::SetAudioClip(const char* clipName)
{
	_audioClip = entity->scene->engine->assetWarehouse->GetAudioClip(clipName);

	if (_audioClip == nullptr)
	{
		std::string name = clipName;
		Debug::LogError("AudioSource couldn't find " + name + ". This AudioSource will not do anything! ", this);
	}
}

void AudioSource::Play()
{
	if (_audioClip == nullptr) return;

	// Have the audio mixer automatically choose the
	// channel it should play on. Give it the clip,
	// and we dont want it to repeat. so set it to 0.
	AudioManager::PlayClip(_audioClip);
}

void AudioSource::Play(const char* clipName)
{
	SetAudioClip(clipName);

	if (_audioClip == nullptr) return;

	// Have the audio mixer automatically choose the
	// channel it should play on. Give it the clip,
	// and we dont want it to repeat. so set it to 0.
	AudioManager::PlayClip(_audioClip);
}

