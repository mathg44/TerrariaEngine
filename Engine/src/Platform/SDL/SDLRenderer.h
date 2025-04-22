#pragma once
#include "Engine/Renderer.h"

#include <SDL.h>

namespace Engine {

	class SDLRenderer : public Renderer
	{
	public:
		SDLRenderer(SDL_Window* window);
		virtual ~SDLRenderer() override;

		virtual void Clear() override;
		virtual void Present() override;
		virtual void SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) override;
		virtual void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) override;

		virtual inline void* GetNativeRenderer() const override { return m_SDLRenderer; };
	private:
		void Init(SDL_Window* window);
		void ShutDown();
	private:
		SDL_Renderer* m_SDLRenderer;
		SDL_Color m_ClearColor;
		SDL_Color m_DrawColor;
	};
}