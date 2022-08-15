#include "Hzpch.h"

#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {
#define BINDE_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Hazel::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BINDE_EVENT_FN(OnEvent));
	}

	Hazel::Application::~Application()
	{
	}

	void Hazel::Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		};
	}

	void Hazel::Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BINDE_EVENT_FN(OnWindowClosed));
	}

	bool Application::OnWindowClosed(WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}

	Hazel::Application* Hazel::CreateAppliation()
	{
		return nullptr;
	}

}

