#pragma once
#include "Hazel/Layer.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"

namespace Hazel {

	class HAZEL_API ImGuiLayer : public Hazel::Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressdEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEventEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEventEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEventEvent(KeyTypedEvent& e);
		bool OnWindowResizeEventEvent(WindowResizeEvent& e);
		bool OnWindowCloseEventEvent(WindowCloseEvent& e);
	private:
		float m_Time = 0.0f;
	};
}
