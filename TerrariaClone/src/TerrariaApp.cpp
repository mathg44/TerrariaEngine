#include <Engine.h>

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{ }

	void OnUpdate() override
	{
		ENG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Engine::Event& event) override
	{
		ENG_TRACE("{0}", event.ToString());
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