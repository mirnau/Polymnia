#pragma once

#include <memory>

#include "Core.h"
#include "Log.h"

namespace Polymnia 
{ 
	class POLYMNIA_API Application
	{
		LoggerTool::Log* log;

	public:
		Application();
		virtual ~Application();

		void Run();

	};
	
	// To be defined in client
	std::unique_ptr<Polymnia::Application> CreateApplication();
}

