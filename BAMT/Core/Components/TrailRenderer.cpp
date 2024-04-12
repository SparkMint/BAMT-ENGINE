#include "TrailRenderer.h"

#include "Scene.h"

void TrailRenderer::Start()
{
	Renderer::Start();
}

void TrailRenderer::InitializeTrail(int segments, float thickness)
{
	trailLength = segments;
	trailThickness = thickness;

	// Clear out any previous trail stuff.
	for (auto ent : trailParts)
	{
		delete(ent);
	}

	for (int i = trailLength; i > 0; --i)
	{
		auto* trailEnt = entity->scene->AddEntity();

		// Use linear interpolation in order to make the trail sizes look good.
		float t = (float)i / trailLength;
		float size = (trailThickness * entity->transform->scale) * (1.0f - t) + trailThickness / trailLength * t;

		auto* renderer = trailEnt->AddComponent<RectRenderer>(size, size, true);
		renderer->colour = colour;
		trailEnt->renderLayer = entity->renderLayer - 1;
		trailParts.push_back(trailEnt);
		previousPositions.push_back(*entity->transform->GetPosition());
	}
}

void TrailRenderer::Update(float* timeStep)
{
    if (trailParts.empty()) return;

	for (int i = 0; i < trailParts.size(); ++i)
	{
		trailParts[i]->transform->SetPosition(&previousPositions[i]);

		if (previousPositions.size() > trailLength)
		{
			previousPositions.erase(previousPositions.begin());
		}
	}

	previousPositions.push_back(*entity->transform->GetPosition());
}

void TrailRenderer::ShowTrail(bool active)
{
	for (auto ent : trailParts)
	{
		ent->active = active;
	}
}
