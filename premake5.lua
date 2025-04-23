workspace "TerrariaEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (solution dir)
	IncludeDir = {}
	IncludeDir["glm"] = "Engine/vendor/glm"

	startproject "TerrariaClone"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "engpch.h"
	pchsource "Engine/src/engpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	files
    {
        "%{prj.name}/vendor/imgui/imgui.cpp",
        "%{prj.name}/vendor/imgui/imgui_demo.cpp",
        "%{prj.name}/vendor/imgui/imgui_draw.cpp",
        "%{prj.name}/vendor/imgui/imgui_tables.cpp",
        "%{prj.name}/vendor/imgui/imgui_widgets.cpp",
        "%{prj.name}/vendor/imgui/backends/imgui_impl_sdl2.cpp",
        "%{prj.name}/vendor/imgui/backends/imgui_impl_sdlrenderer2.cpp"
    }
    
    -- Then exclude ImGui files from using PCH
    filter { "files:Engine/vendor/imgui/**.cpp" }
        flags { "NoPCH" }
        defines { "IMGUI_API=__declspec(dllexport)" }
    filter { }
    
    filter { "files:Engine/src/**.cpp" }
        defines { "IMGUI_API=__declspec(dllexport)" }
    filter { }

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/SDL2/include",
        "%{prj.name}/vendor/SDL2_image/include",
		"%{prj.name}/vendor/imgui",
		"%{IncludeDir.glm}"
	}

	libdirs
	{
		"%{prj.name}/vendor/SDL2/lib/x64",
		"%{prj.name}/vendor/SDL2_image/lib/x64"
	}

	links
	{
		"SDL2.lib",
		"SDL2_image.lib"
	}

	filter "system:windows"
		cppdialect "C++23"
		systemversion "latest"

		defines
		{
			"ENG_PLATFORM_WINDOWS",
			"ENG_BUILD_DLL"
		}

		buildoptions { "/utf-8" }

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TerrariaClone"),
			("{COPY} %{prj.location}/vendor/SDL2/lib/x64/SDL2.dll ../bin/" .. outputdir .. "/TerrariaClone"),
			("{COPY} %{prj.location}/vendor/SDL2_image/lib/x64/SDL2_image.dll ../bin/" .. outputdir .. "/TerrariaClone")
		}

	filter "configurations:Debug"
		defines "ENG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ENG_RELEASE"
		runtime "Release"
		optimize "On"

project "TerrariaClone"
	location "TerrariaClone"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine/vendor/spdlog/include",
		"Engine/src",
		"%{IncludeDir.glm}",
		"Engine/vendor"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++23"
		systemversion "latest"

		defines
		{
			"ENG_PLATFORM_WINDOWS",
			"IMGUI_API=__declspec(dllimport)"
		}

		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "ENG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ENG_RELEASE"
		runtime "Release"
		optimize "On"

