workspace "HazelVariant"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "HazelVariant/vendor/GLFW/include"
	IncludeDir["Glad"] = "HazelVariant/vendor/Glad/include"
	IncludeDir["Imgui"] = "HazelVariant/vendor/imgui"

	include "HazelVariant/vendor/GLFW"
	include "HazelVariant/vendor/Glad"
	include "HazelVariant/vendor/imgui"

	project "HazelVariant"
		location "HazelVariant"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir ..   "/%{prj.name}")
		objdir ("bin-int/" .. outputdir ..   "/%{prj.name}")

		pchheader "Hzpch.h"
		pchsource "HazelVariant/src/Hzpch.cpp"

		files 
		{ 
			"%{prj.name}/src/**.h", 
			"%{prj.name}/src/**.cpp",
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.Imgui}"
		}

		links 
		{ 
			"GLFW",
			"Glad",
			"Imgui",
			"opengl32.lib"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"HZ_PLATFOR_WINDOWS",
				"HZ_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}

			postbuildcommands 
			{ 
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}
		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/MDd"
			symbols "On"
			
		filter "configurations:Release"
			defines "HZ_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "HZ_DIST"
			buildoptions "/MD"
			optimize "On"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

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
			"HazelVariant/vendor/spdlog/include"
		}

		links
		{
			"HazelVariant"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines
			{
				"HZ_PLATFOR_WINDOWS"
			}


		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/MDd"
			symbols "On"
			
		filter "configurations:Release"
			defines "HZ_RELEASE"
			buildoptions "/MD"
			optimize "On"

		filter "configurations:Dist"
			defines "HZ_DIST"
			buildoptions "/MD"
			optimize "On"

