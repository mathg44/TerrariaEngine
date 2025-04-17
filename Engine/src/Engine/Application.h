#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning = true;
	};

	// TODO: Define in CLIENT
	Application* CreateApplication();
}

