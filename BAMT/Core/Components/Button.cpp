#include "Button.h"

void Button::Start()
{
	buttonInner = entity->AddComponent<RectRenderer>();
	
	buttonInner->fillRect = true;

	buttonBorder = entity->AddComponent<SpriteRenderer>();
	buttonBorder->SetSprite("gridSquare.png");
}

void Button::Update(float* timeStep)
{
	buttonInner->width = width;
	buttonInner->height = height;

	buttonBorder->width = width;
	buttonBorder->height = height;

	// Get the direction of the mouse on the screen.
	const Vector2 mousePos = Input::GetMousePosition();

	if (VectorMath::OverlapOnAxis(mousePos.x, 0, entity->transform->GetX(), width)
	&& VectorMath::OverlapOnAxis(mousePos.y, 0, entity->transform->GetY(), height))
	{
		if (Input::GetMouseButtonDown(SDL_BUTTON_LEFT))
		{
			buttonInner->colour = pressedColour;
			buttonPressed = true;
		}
		else
		{
			buttonInner->colour = highlightedColour;
			buttonPressed = false;
		}
	}
	else
	{
		buttonInner->colour = normalColour;
		buttonPressed = false;
	}
}