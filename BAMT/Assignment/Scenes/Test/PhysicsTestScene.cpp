#include "PhysicsTestScene.h"

void PhysicsTestScene::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;
	const float thickness = 5;

	// Left
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(-thickness / 2, height / 2);
	collisionTest->width = thickness;
	collisionTest->height = height;
	collisionTest->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	// Top Wall
	auto* collisionTest1 = AddEntity<StaticCollider>();

	collisionTest1->GetComponent<Transform>()->SetPosition(width / 2, -thickness / 2);
	collisionTest1->width = width;
	collisionTest1->height = thickness;
	collisionTest1->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + thickness / 2, height / 2);
	collisionTest2->width = thickness;
	collisionTest2->height = height;
	collisionTest2->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 2);
	collisionTest3->width = width;
	collisionTest3->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	AddEntity<CoordinateGrid>();

	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			const auto thing = AddEntity<Entity>();
			thing->GetComponent<Transform>()->SetPosition(2 + (j * .26f), 2 + (i * .26f));
			auto* rb = thing->AddComponent<RigidBody>();
			rb->width = .25f;
			rb->height = .25f;
			rb->bounciness = .2f;
			rb->drag = 2;
			rb->maxVelocity = 10;
			rb->mass = 1;
			auto* rr = thing->AddComponent<RectRenderer>();
			rr->width = .25f;
			rr->height = .25f;
			rr->fillRect = true;

			int r = rand() & 255;
			int g = rand() & 255;
			int b = rand() & 255;
			rr->colour = { r, g ,b, 255 };
		}
	}

	const auto thing = AddEntity<Entity>();
	thing->GetComponent<Transform>()->SetPosition(1,1);
	auto* rb = thing->AddComponent<RigidBody>();
	rb->width = .25f;
	rb->height = .25f;
	rb->bounciness = .2f;
	rb->drag = 2;
	rb->maxVelocity = 10;
	rb->mass = 1;
	auto* rr = thing->AddComponent<RectRenderer>();
	rr->width = .25f;
	rr->height = .25f;
	rr->fillRect = true;

	int r = rand() & 255;
	int g = rand() & 255;
	int b = rand() & 255;
	rr->colour = { r, g ,b, 255 };
	thing->AddComponent<KeyboardMovement>()->currentMovementSpeed = 10;


	gravity = { 0, 5 };
}