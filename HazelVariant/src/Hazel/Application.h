#pragma once


#include "Core.h"
#include "Window.h"

#include "Layer.h"
#include "Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"


namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		bool OnWindowClosed(WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverLayer(Layer* layer);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in Client
	Application* CreateAppliation();
}


