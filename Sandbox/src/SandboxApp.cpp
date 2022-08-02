#include <Hazel.h>

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Hazel::Application* Hazel::CreateAppliation()
{
	return new Sandbox();
}
