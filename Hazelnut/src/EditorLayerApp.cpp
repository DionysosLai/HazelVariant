#include <Hazel.h>
#include <Hazel/Core/EntoryPoint.h>

#include "EditorLayer.h"

namespace Hazel {
	class HazelEditor : public Hazel::Application
	{
	public:
		HazelEditor() : Application("Hazel Editor")
		{
			//PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}
		~HazelEditor()
		{

		}
	};

	Application* CreateAppliation()
	{
		return new HazelEditor();
	}
}

