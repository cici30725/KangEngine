#pragma once
#include "Core.h"
namespace Kang {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	
	Application* CreateApplication();
}


