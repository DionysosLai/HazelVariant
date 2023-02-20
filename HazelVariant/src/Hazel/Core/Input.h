#pragma once

#include "Hazel/Core/Base.h"
#include "Hazel/Core/KeyCodes.h"
#include "Hazel/Core/MouseCode.h"

namespace Hazel {
	class HAZEL_API Input
	{
	public:

		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
