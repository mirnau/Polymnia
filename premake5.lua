workspace "Polymnia"
    architecture "x64"
    configurations 
    {
        "Debug", 
        "Release", 
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Logger"
    location "Logger"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") --bin-int is obj

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Logger/Source"
    }


    filter "system:windows"
        cppdialect"C++20"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "PL_PLATFORM_WINDOWS",
            "LOG_BUILD_DLL"            
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Client"
        }

project "Polymnia"
    location "Polymnia"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") --bin-int is obj

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Logger/Source"
    }
    
    links
    {
        "Logger"
    }

    filter "system:windows"
        cppdialect"C++20"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "PL_PLATFORM_WINDOWS",
            "PL_BUILD_DLL"
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Client"
        }
        
    filter "configurations:Debug"
        defines "PL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        optimize "On"
   
project "Client"
    location "Client"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") --bin-int is obj

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Logger/Source",
        "Polymnia/Source"
    }
    

    filter "system:windows"
        cppdialect"C++20"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "PL_PLATFORM_WINDOWS"
        }

        links
        {
            "Logger",
            "Polymnia"
        }

    filter "configurations:Debug"
        defines "PL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        optimize "On"