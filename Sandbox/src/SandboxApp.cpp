#include <Hazel.h>
#include <Hazel/Core/EntoryPoint.h>

#include "Sandbox2D.h"



class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateAppliation()
{
	return new Sandbox();
}
