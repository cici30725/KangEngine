#include "hzpch.h"
#include "Application.h"
#include <glad/glad.h>


namespace Kang {
#define BIND_EVENT_FNC(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FNC(OnEvent));
	}


	Application::~Application()
	{
	}


	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FNC(OnWindowClose));

		HZ_CORE_INFO(event.ToString());

		for (auto i = m_LayerStack.end(); i != m_LayerStack.begin();) {
			(*--i)->OnEvent(event);
			if (event.Handled)
				break;
		}

	}
	
	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverLay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}
