workspace "HazelVariant"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HazelVariant/vendor/GLFW/include"
IncludeDir["Glad"] = "HazelVariant/vendor/Glad/include"
IncludeDir["Imgui"] = "HazelVariant/vendor/imgui"
IncludeDir["glm"] = "HazelVariant/vendor/glm"
IncludeDir["stb_image"] = "HazelVariant/vendor/stb_image"

group "Dependencies"
	include "HazelVariant/vendor/GLFW"
	include "HazelVariant/vendor/Glad"
	include "HazelVariant/vendor/imgui"

group ""

project "HazelVariant"
	location "HazelVariant"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir ..   "/%{prj.name}")
	objdir ("bin-int/" .. outputdir ..   "/%{prj.name}")

	pchheader "Hzpch.h"
	pchsource "HazelVariant/src/Hzpch.cpp"

	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.Imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"Imgui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HZ_PLATFOR_WINDOWS",
			"HZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir ..   "/%{prj.name}")
	objdir ("bin-int/" .. outputdir ..   "/%{prj.name}")

	files 
	{ 
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"HazelVariant/src",
		"HazelVariant/vendor/spdlog/include",
		"HazelVariant/vendor",
		"%{IncludeDir.glm}",
	}

	links
	{
		"HazelVariant"
	}

	ignoredefaultlibraries { "libcmt" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HZ_PLATFOR_WINDOWS"
		}


	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"

