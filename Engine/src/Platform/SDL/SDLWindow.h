#pragma once

#include "Engine/Window.h"

#include <SDL.h>

namespace Engine {

	class SDLWindow : public Window
	{
	public:
		SDLWindow(const WindowProps& props);
		virtual ~SDLWindow();

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }

		virtual inline void SetEventCallback(const EventCallbackFn& callback) override 
		{ m_Data.EventCallback = callback; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual inline Renderer& GetRenderer() override { return *m_Renderer; }
		virtual inline void* GetNativeWindow() const override { return m_SDLWindow; };

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
		void ProcessSDLEvent(const SDL_Event& e);
	private:
		SDL_Window* m_SDLWindow;
		std::unique_ptr<Renderer> m_Renderer;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

