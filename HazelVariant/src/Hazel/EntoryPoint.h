#pragma once
#include "Application.h"

#ifdef HZ_PLATFOR_WINDOWS
extern Hazel::Application* Hazel::CreateAppliation();

int main(int argc, char** argv)
{
	printf("Welcome Hazel Engin！！");
	auto app = Hazel::CreateAppliation();
	app->Run();
	delete app;
}
#else
#error Hazel only support Windows!
#endif