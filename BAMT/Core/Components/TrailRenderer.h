#ifndef BAMT_TRAIL_RENDERER
#define BAMT_TRAIL_RENDERER

#include "RectRenderer.h"

class TrailRenderer : public Renderer
{
	std::vector<Entity*> trailParts;
	std::vector<Vector2> previousPositions;

	float time;

	public:
		int trailLength = 3;
		float trailThickness = .25f;

		void Start() override;
		void InitializeTrail(int segments, float thickness);
		void Update(float* timeStep) override;

		void ShowTrail(bool active);
};
#endif