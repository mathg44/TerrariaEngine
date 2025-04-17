#pragma once

#ifdef ENG_PLATFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	// Temporary
	Engine::Log::Init();
	ENG_CORE_WARN("Log initialised!");
	ENG_CORE_INFO("Hello!");

	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif