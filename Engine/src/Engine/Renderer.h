#pragma once
#include "Engine/Core.h"
#include "SDL.h"

namespace Engine {

	class ENGINE_API Renderer
	{
	public:
		Renderer(SDL_Window* window);
		~Renderer();

		void Clear();
		void Present();
		inline void SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) { m_ClearColor = { r, g, b, a }; }
		void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255); 
	private:
		void Init(SDL_Window* window);
		void ShutDown();
	private:
		SDL_Renderer* m_SDLRenderer;
		SDL_Color m_ClearColor;
		SDL_Color m_DrawColor;
	};
}