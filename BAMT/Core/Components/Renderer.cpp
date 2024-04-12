#include "Renderer.h"

void Renderer::Start()
{
	_transform = entity->GetComponent<Transform>();

	if (_transform == nullptr)
	{
		Debug::LogWarn("Renderer couldn't find Transform in this Entity, Adding one now.", entity);
		_transform = entity->AddComponent<Transform>();
	}
}