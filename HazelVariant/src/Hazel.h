#pragma once

// For use by Hazel applications
#include <stdio.h>
#include "Hazel/Core/Application.h"
#include "Hazel/Core/Log.h"
#include "Hazel/Core/Layer.h"
#include "Hazel/Core/Input.h"
#include "Hazel/Core/KeyCodes.h"
#include "hazel/Core/MouseCode.h"
#include "Hazel/Core/Base.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/Event.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

#include "Hazel/Core/Timestep.h"

// ---Renderer------------------------
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Renderer/Renderer2D.h"
#include "Hazel/Renderer/RenderCommand.h"
#include "Hazel/Renderer/Texture.h"
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/Framebuffer.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/OrthographicCameraController.h"
#include "Hazel/Renderer/OrthographicCamera.h"

//  ----------------------------------------------