#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern EngineCore::Application* EngineCore::CreateApplication();

int main(int argc, char** argv)
{
	auto app = EngineCore::CreateApplication();
	app->Run();
	delete app;
}


#endif