#pragma once

#ifdef HZ_PLATFOR_WINDOWS
extern Hazel::Application* Hazel::CreateAppliation();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	HZ_INFO("Hello");
	

	//printf("Welcome Hazel Engin！！");
	auto app = Hazel::CreateAppliation();
	app->Run();
	delete app;
}
#else
#error Hazel only support Windows!
#endif