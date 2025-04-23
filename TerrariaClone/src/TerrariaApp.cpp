#include <Engine.h>

#include <imgui/imgui.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		if (Engine::Input::IsKeyPressed(ENG_SCANCODE_A))
		{
			ENG_TRACE("A key pressed!");
		}
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Engine::Event& event) override
	{
		// ENG_TRACE("{0}", event.ToString());
	}
};

class TerrariaApp : public Engine::Application
{
public:
	TerrariaApp()
	{
		PushLayer(new ExampleLayer());
	}

	~TerrariaApp()
	{

	}
	
};

Engine::Application* Engine::CreateApplication()
{
	return new TerrariaApp();
}