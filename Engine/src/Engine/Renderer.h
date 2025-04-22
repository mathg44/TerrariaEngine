#pragma once
#include "Engine/Core.h"

struct SDL_Window;

namespace Engine {

	class ENGINE_API Renderer
	{
	public:
		static Renderer* Create(void* window);
		virtual ~Renderer() = default;

		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual void SetClearColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) = 0;
		virtual void SetDrawColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) = 0;

		virtual void* GetNativeRenderer() const = 0;
	};
}