#include <Engine.h>

class TerrariaApp : public Engine::Application
{
public:
	TerrariaApp()
	{

	}
	~TerrariaApp()
	{

	}
	
};

Engine::Application* Engine::CreateApplication()
{
	return new TerrariaApp();
}