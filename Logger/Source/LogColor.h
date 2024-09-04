#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <iostream>
#include <Windows.h>

namespace LoggerTool
{
	enum Swatch 
	{
		Default,
        Green,
		Yellow,
		Red,
	};

	class LogColor
	{
	public:
		LogColor() = default;
		~LogColor() =default;
		
        void Set(Swatch swatch)
        {
#if PL_PLATFORM_WINDOWS
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            if(hConsole == INVALID_HANDLE_VALUE) return;

            switch(swatch)
            {
                case LoggerTool::Default:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
                case LoggerTool::Green:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    break;
                case LoggerTool::Yellow:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    break;
                case LoggerTool::Red:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    break;
            }

#else
            switch(swatch)
            {
                case LoggerTool::Default:
                    std::cout << "\033[0m";
                    break;
                case LoggerTool::Yellow:
                    std::cout << "\033[1;33m";
                    break;
                case LoggerTool::Red:
                    std::cout << "\033[1;31m";
                    break;
                case LoggerTool::Green:
                    std::cout << "\033[1;32m";
                    break;
                default:
                    std::cout << "\033[0m";
                    break;
            }
#endif
        }

	};
}