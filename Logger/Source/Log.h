#pragma once

#include<iostream>
#include<memory>
#include <mutex>
#include <string>

#include "Core.h"
#include "LogColor.h"

#define LOG_MESSAGE(level,...) LoggerTool::Log::GetInstance()->Message(level, __VA_ARGS__)

namespace LoggerTool
{
	enum Level
	{
		Trace,
		Info,
		Warning,
		Error,
		Fatal,
	};

	class LOG_TOOL_API Log
	{

	private:
		LogColor* color;
		const char* LevelToString(Level level) const;

		Log(Log&) = delete;
		Log(Log&&) = delete;

		Log& operator=(const Log&) = delete;
		Log& operator=(Log&&) = delete;

		static std::mutex s_m_mutex;
		static std::shared_ptr<Log> Instance;

	public:

		Log() noexcept;
		~Log() noexcept;

		static std::shared_ptr<Log> GetInstance();

		template<typename ...Args>
		void Message(Level level, Args... args)
		{

			if(!color)
			{
				throw std::runtime_error("Color object is not initialized");
			}

			switch(level)
			{
				case LoggerTool::Trace:
				case LoggerTool::Info:
					color->Set(Swatch::Green);
					break;
				case LoggerTool::Warning:
					color->Set(Swatch::Yellow);
					break;
				case LoggerTool::Error:
				case LoggerTool::Fatal:
					color->Set(Swatch::Red);
					break;
				default:
					break;
			}
			
			std::cout << LevelToString(level) << " ";

			color->Set(Swatch::Default);

			(std::cout << ... << args) << std::endl;
		}
	};
}