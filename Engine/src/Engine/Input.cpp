#include "engpch.h"
#include "Input.h"

namespace Engine {

	Input* Input::s_Instance = new Input();

	bool Input::IsKeyPressed(SDL_Scancode key)
	{
		const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
		return keyboardState[key] != 0;
	}

	bool Input::IsMouseButtonPressed(Uint8 button)
	{
		const Uint32 mouseState = SDL_GetMouseState(NULL, NULL);
		return (mouseState & SDL_BUTTON(button)) != 0;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		int xPos, yPos;
		const Uint32 mouseState = SDL_GetMouseState(&xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float Input::GetMouseX()
	{
		auto [x, y] = GetMousePosition();
		return x;
	}

	float Input::GetMouseY()
	{
		auto [x, y] = GetMousePosition();
		return y;
	}
}
