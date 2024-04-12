#ifndef BAMT_BUTTON
#define BAMT_BUTTON

#include "Component.h"
#include "RectRenderer.h"
#include "SpriteRenderer.h"
#include "Input.h"

class Button : public Component
{
	RectRenderer* buttonInner = nullptr;
	SpriteRenderer* buttonBorder = nullptr;

	Colour normalColour = Colour{100, 100, 100, 255};
	Colour highlightedColour = Colour{ 50, 50, 50, 255 };
	Colour pressedColour = BAMT_COLOUR_BLUE;

	public:
		float width = 1;
		float height = 1;

	    // This is pretty jank. But it works so :/
		/// <summary>
		/// Used to tell if the button is currently being pressed.
		/// </summary>
		bool buttonPressed = false;

		void Start() override;
	    void Update(float* timeStep) override;
};
#endif