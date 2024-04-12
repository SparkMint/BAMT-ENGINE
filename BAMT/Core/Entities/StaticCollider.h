#ifndef BAMT_STATIC_COLLIDER
#define BAMT_STATIC_COLLIDER

#include "../../Core/Components/RectRenderer.h"
#include "../../Core/Components/RigidBody.h"
#include "../../Core/ECS/Entity.h"

class StaticCollider : public Entity
{
public:
	StaticCollider();
	StaticCollider(float w, float h);
	RigidBody* rigidBody = nullptr;
	RectRenderer* rectRenderer = nullptr;

	// Shared Values
	float width = 0;
	float height = 0;

	// RigidBody Values
	float bounciness = 1;

	// RectRenderer Values
	bool fillRect = true;


	void Start() override;
	void Update(float* timeStep) override;
};
#endif
