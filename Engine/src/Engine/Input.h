#pragma once
#include "Engine/Core.h"

namespace Engine {

	class ENGINE_API Input
	{
	public:

		// Keyboard state
		static bool IsKeyPressed(int keyCode);

		// Mouse State
		static bool IsMouseButtonPressed(int button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

	private:
		static Input* s_Instance;
	};
}

