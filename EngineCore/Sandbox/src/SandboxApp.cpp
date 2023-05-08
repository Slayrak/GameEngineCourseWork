#include <Engine.h>

class Sandbox : public EngineCore::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

EngineCore::Application* EngineCore::CreateApplication()
{
	return new Sandbox();
}