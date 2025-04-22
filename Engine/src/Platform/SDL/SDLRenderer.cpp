#include "engpch.h"
#include "SDLRenderer.h"

namespace Engine {

	Renderer* Renderer::Create(void* window)
	{
		return new SDLRenderer(static_cast<SDL_Window*>(window));
	}

	SDLRenderer::SDLRenderer(SDL_Window* window)
		: m_SDLRenderer(nullptr), m_ClearColor{ 0, 0, 0, 255 }, m_DrawColor{ 255, 255, 255, 255 }
	{
		Init(window);
	}

	SDLRenderer::~SDLRenderer()
	{
		ShutDown();
	}

	void SDLRenderer::Clear()
	{
		SDL_SetRenderDrawColor(m_SDLRenderer,
			m_ClearColor.r,
			m_ClearColor.g,
			m_ClearColor.b,
			m_ClearColor.a);
		SDL_RenderClear(m_SDLRenderer);
	}

	void SDLRenderer::Present()
	{
		SDL_RenderPresent(m_SDLRenderer);
	}

	void SDLRenderer::SetClearColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		m_ClearColor = { r, g, b, a };
	}

	void SDLRenderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		m_DrawColor = { r, g, b, a };
		SDL_SetRenderDrawColor(m_SDLRenderer, r, g, b, a);
	}

	void SDLRenderer::Init(SDL_Window* window)
	{
		ENG_CORE_INFO("Initializing Renderer");

		m_SDLRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		ENG_CORE_ASSERT(m_SDLRenderer, "Failed to create SDL Renderer!");

		SetClearColor(0, 0, 0);
		SetDrawColor(255, 255, 255);
	}

	void SDLRenderer::ShutDown()
	{
		SDL_DestroyRenderer(m_SDLRenderer);
		m_SDLRenderer = nullptr;
	}

}