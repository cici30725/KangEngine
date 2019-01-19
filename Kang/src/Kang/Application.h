#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

namespace Kang {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& event);	// Still do not know what this function is used for
		void Run();
		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};
	
	Application* CreateApplication();
}


