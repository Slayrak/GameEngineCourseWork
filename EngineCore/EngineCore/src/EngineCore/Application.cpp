#include "Application.h"

#include "EngineCore/Events/ApplicationEvent.h"
#include "EngineCore/Log.h"

namespace EngineCore
{
	Application::Application()
	{

	}


	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		ENGINE_TRACE_LOG(e.ToString());
		ENGINE_TRACE_LOG("Am I alive?");

		while (true);
	}
}
