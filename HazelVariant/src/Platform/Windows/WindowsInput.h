#pragma once
#include <Hazel/Core/Input.h>
namespace Hazel {
	class WindowsInput : public Input
	{
	public:
		virtual bool IsKeyPressedImpl(KeyCode keycode) override;

		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;

	private:

	};
	
}