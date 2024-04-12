#include "Input.h"

namespace Input
{
	/// <summary>
	/// All Keys that SDL supports.
	/// </summary>
	std::unordered_map<int, bool> _keyStatesLastFrame;
	std::unordered_map<int, bool> _keyStates;

	/// <summary>
	/// All mouse buttons.
	/// </summary>
	std::unordered_map<int, bool> _mouseStateLastFrame;
	std::unordered_map<int, bool> _mouseStates;

	SDL_Renderer* _renderer;
	void SetRenderer(SDL_Renderer* renderer)
	{
		_renderer = renderer;
	}

	void GetInputs()
	{
		_keyStatesLastFrame = _keyStates;
		_mouseStateLastFrame = _mouseStates;
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					_keyStates[SDL_QUIT] = true;
					break;

				case SDL_WINDOWEVENT_MOVED:
					_keyStates[SDL_WINDOWEVENT_MOVED] = true;
					break;

				case SDL_MOUSEBUTTONDOWN:
					_mouseStates[event.button.button] = true;
					break;

				case SDL_MOUSEBUTTONUP:
					_mouseStates[event.button.button] = false;
					break;

				case SDL_KEYDOWN:
					_keyStates[event.key.keysym.sym] = true;
					break;

				case SDL_KEYUP:
					_keyStates[event.key.keysym.sym] = false;
					break;

				default: 
					break;
			}
		}
	}

	bool GetKeyHold(const SDL_Keycode key)
	{
		return _keyStates[key];
	}

	bool GetKeyDown(const SDL_Keycode key)
	{
		return !_keyStatesLastFrame[key] && _keyStates[key];
	}

	bool GetMouseButtonHold(const int button)
	{
		return _mouseStates[button];
	}

	bool GetMouseButtonDown(const int button)
	{
		return !_mouseStateLastFrame[button] && _mouseStates[button];
	}

	Vector2 GetMousePosition()
	{
		// Get the mouses X and Y position.
		int mouseX, mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);

		float localSpaceMouseX = 0;
		float localSpaceMouseY = 0;

		SDL_RenderWindowToLogical(_renderer, mouseX, mouseY, &localSpaceMouseX, &localSpaceMouseY);
		// Return it!
		return { localSpaceMouseX / BAMT_WORLD_SCALE,  localSpaceMouseY / BAMT_WORLD_SCALE };
	}
}