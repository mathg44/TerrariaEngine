#pragma once
#include "engpch.h"
#include "Engine/Core.h"
#include "Engine/Events/Event.h"
#include <SDL.h>

namespace Engine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Terraria Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{ }
	};

	class Window 
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowProps& props);
		~Window();

		void OnUpdate();

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }

		// Window Attributes
		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallBack = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const;

		static Window* Create(const WindowProps& props = WindowProps());
	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		SDL_Window* m_SDLWindow;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallBack;
		};

		WindowData m_Data;
	};
}