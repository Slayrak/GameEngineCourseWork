workspace "EngineCore"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLAD"] = "EngineCore/vendor/GLAD/include"

include "EngineCore/vendor/GLAD"

project "EngineCore"
    location "EngineCore"
    kind "SharedLib"
    language "C++"

    targetdir ("x64/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "EngineCore/vendor/spdlog/include",
        "EngineCore/src",
        "%{IncludeDir.GLAD}"
    }

    links
    {
        "GLAD"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    defines
    {
        "ENGINE_PLATFORM_WINDOWS",
        "ENGINE_BUILD_DLL",
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../x64/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "ENGINE_CORE_DEBUG"
        symbols "On"

    filter "configurations:Release"
    defines "ENGINE_CORE_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "ENGINE_CORE_DIST"
    optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("x64/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "EngineCore/vendor/spdlog/include",
        "EngineCore/src"
    }

    links
    {
        "EngineCore"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    defines
    {
        "ENGINE_PLATFORM_WINDOWS",
    }

    filter "configurations:Debug"
        defines "ENGINE_CORE_DEBUG"
        symbols "On"

    filter "configurations:Release"
    defines "ENGINE_CORE_RELEASE"
    optimize "On"

    filter "configurations:Dist"
    defines "ENGINE_CORE_DIST"
    optimize "On"