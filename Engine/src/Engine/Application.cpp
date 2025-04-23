#include "engpch.h"
#include "Application.h"

#include "Engine/Log.h"
#include "Engine/Input.h"

namespace Engine {



	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ENG_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ENG_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}
	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		ENG_CORE_TRACE("{0}", e.ToString());

		EventDispatcher dispatcher(e);

		// If the Event e is of type <T>, calls the binded function.
		dispatcher.Dispatch<WindowClosedEvent>(ENG_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(ENG_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
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
			// Clear the screen
			m_Window->GetRenderer().Clear();

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();

			// Present final frame
			m_Window->GetRenderer().Present();

			// Testing Input
			//auto [x, y] = Input::GetMousePosition();

			m_Window->OnUpdate();
		}
	}
}
