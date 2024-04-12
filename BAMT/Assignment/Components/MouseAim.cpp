#include "MouseAim.h"

Vector2 MouseAim::GetAimDirection(const Vector2* sourcePosition)
{
	// Get the direction of the mouse on the screen.
	const Vector2 mouseDir = Input::GetMousePosition();

	// Calculate the direction the mouse is pointing.
	const Vector2 dir = mouseDir - *sourcePosition;

	// Return the direction created.
	return dir;
}