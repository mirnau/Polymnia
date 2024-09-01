#pragma once
#include "Core.h"

namespace Polymnia 
{ 
	class POLYMNIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};
	
	// To be defined in client
	Application* CreateApplication();
}

