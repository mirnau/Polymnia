#pragma once

#include <memory>

#include "Core.h"
#include "Log.h"

namespace Polymnia 
{ 
	class POLYMNIA_API Application
	{
	public:
		Application() noexcept = default;
		virtual ~Application() noexcept = default;

		void Run();
	};
	
	// To be defined in client
	std::unique_ptr<Polymnia::Application> CreateApplication();
}

