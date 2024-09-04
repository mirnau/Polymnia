#pragma once
#include "Application.h"

namespace Polymnia 
{ 
	Application::Application() : 
		log(LoggerTool::Log::GetInstance())
	{


	}
	
	Application::~Application()
	{
		LoggerTool::Log::DestroyInstance();
	}
	
	void Application::Run()
	{
		LOG_MESSAGE(LoggerTool::Level::Trace, "Log Library Hello");
		
		while (true)
		{
		}
	}
}