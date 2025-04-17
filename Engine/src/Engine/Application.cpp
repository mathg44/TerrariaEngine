#include "engpch.h"
#include "Application.h"

#include "Engine/Log.h"

namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		ENG_CORE_TRACE("{0}", e.ToString());

		EventDispatcher dispatcher(e);

		// If the Event e is of type <T>, calls the binded function.
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_IsRunning = false;

		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		// Window resize logic
		return true;
	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			m_Window->OnUpdate();
		}
	}
}
