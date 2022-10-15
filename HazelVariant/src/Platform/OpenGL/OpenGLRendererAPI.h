#pragma once

#include "Hazel/Renderer/RendererAPI.h"

namespace Hazel {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init();
		virtual void SetClearColor(const glm::vec4& color);
		virtual void Clear();
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
	private:

	};
}