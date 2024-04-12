#include "AssignmentMenu.h"

void AssignmentMenu::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	const float thickness = 5;

	// Left wall
	auto* collisionTest = AddEntity<StaticCollider>();

	collisionTest->GetComponent<Transform>()->SetPosition(-thickness / 2, height / 2);
	collisionTest->width = thickness;
	collisionTest->height = height * 5;
	collisionTest->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	// Right Wall
	auto* collisionTest2 = AddEntity<StaticCollider>();

	collisionTest2->GetComponent<Transform>()->SetPosition(width + thickness / 2, height / 2);
	collisionTest2->width = thickness;
	collisionTest2->height = height * 5;
	collisionTest2->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };

	// Bottom Wall
	auto* collisionTest3 = AddEntity<StaticCollider>();

	collisionTest3->GetComponent<Transform>()->SetPosition(width / 2, height + thickness / 2);
	collisionTest3->width = width;
	collisionTest3->height = thickness;
	collisionTest3->GetComponent<RectRenderer>()->colour = { 150, 150,150, 255 };


	auto* button = AddEntity();
	button->transform->SetPosition(12.5f, 7.5f);
	startButton = button->AddComponent<Button>();
	startButton->width = 7;
	startButton->height = 2;

	auto* startTextEnt = AddEntity();
	startTextEnt->transform->SetPosition(10, 7.5f);
	auto* startText = startTextEnt->AddComponent<TextRenderer>();
	startText->width = startText->height = 1.5f;
	startText->SetFont("Comfortaa-Bold.ttf");
	startText->SetText("START");
	

	auto* menuEnt = AddEntity();
	menuEnt->transform->SetPosition(width / 2, height / 2);
	auto* menuSprite = menuEnt->AddComponent<SpriteRenderer>(width, height, "menu.png");

	menuEnt->renderLayer = 4;
	button->renderLayer = 5;
	startTextEnt->renderLayer = 6;

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			const auto thing = AddEntity<Entity>();
			thing->GetComponent<Transform>()->SetPosition(width / 2 - 2.5f + (j * 1.01f), -25 + (i * 1.01f));
			auto* rb = thing->AddComponent<RigidBody>();
			rb->width = 1;
			rb->height = 1;
			rb->bounciness = .2f;
			rb->drag = 1;
			rb->maxVelocity = 15;
			rb->mass = 1;
			auto* rr = thing->AddComponent<SpriteRenderer>();

			int powerupSprite = rand() % 4;

			switch (powerupSprite)
			{
				case 0:
					rr->SetSprite("speedItem.png");
					break;

				case 1:
					rr->SetSprite("doublePointsItem.png");
					break;

				case 2:
					rr->SetSprite("shotgunItem.png");
					break;

				case 3:
					rr->SetSprite("rifleItem.png");
					break;
			}
			
			rr->width = 1;
			rr->height = 1;
		}
	}


	const auto thing = AddEntity<Entity>();
	thing->GetComponent<Transform>()->SetPosition(1, 1);
	auto* rb = thing->AddComponent<RigidBody>();
	auto* mouseFollow = thing->AddComponent<MouseFollow>();
	rb->width = 1;
	rb->height = 1;
	rb->bounciness = 0;
	rb->drag = 1;
	rb->maxVelocity = 20;
	rb->mass = 10;
	auto* rr = thing->AddComponent<SpriteRenderer>();
	rr->SetSprite("Logo.png");
	rr->width = 1;
	rr->height = 1;

	_gravSwitchTime = 10;
}

void AssignmentMenu::Update(float* timeStep)
{
	Scene::Update(timeStep);

	if(startButton->buttonPressed)
	{
		engine->GetScene<AssignmentGameLevel>()->active = true;
		active = false;
	}

	if(_gravSwitchTime > 0)
	{
		_gravSwitchTime -= *timeStep;
	}
	else
	{
		negateGravity = !negateGravity;

		if (negateGravity) _gravSwitchTime = 3;
		else _gravSwitchTime = 10;


	}

	if (negateGravity) gravity = { 0, -5 };
	else gravity = { 0, 5 };
}