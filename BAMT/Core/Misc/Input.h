#ifndef BAMT_INPUT
#define BAMT_INPUT

#include "SDL.h"
#include "../Components/Transform.h"
#include "../EngineSettings.h"
#include <unordered_map>

#include "Debug.h"
#include "../EngineManager.h"

namespace Input 
{
	/// <summary>
	/// Gives the input system a reference to a renderer.
	///	Used to convert window space mouse coordinates
	///	into logical space.
	/// </summary>
	void SetRenderer(SDL_Renderer* renderer);

	/// <summary>
	/// Receives Inputs.
	/// </summary>
	void GetInputs();

	/// <summary>
	/// Returns the state of the requested key.
	/// </summary>
	bool GetKeyHold(SDL_Keycode key);

	/// <summary>
	/// Returns the state of the requested key.
	///	Only returns true if it was just pressed. Not if Held.
	/// </summary>
	bool GetKeyDown(const SDL_Keycode key);

	bool GetMouseButtonHold(const int button);

	bool GetMouseButtonDown(const int button);

	Vector2 GetMousePosition();
}
#endif