#pragma once
#include "Engine/Core.h"
#include <SDL.h>

namespace Engine {

	class ENGINE_API Input
	{
	public:

		// Keyboard state
		static bool IsKeyPressed(SDL_Scancode key);

		// Mouse State
		static bool IsMouseButtonPressed(Uint8 button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

	private:
		static Input* s_Instance;
	};
}

