#pragma once
#include "Kang/Window.h"
#include <GLFW/glfw3.h>

namespace Kang {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		void OnUpdate() override;

		// Window attributes
		inline void SetEventCallback(const EventCallbackFnc& fnc) override { m_Data.EventCallback = fnc; }
		void SetVSync(bool enable) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool VSync = false;

			EventCallbackFnc EventCallback;
		};

		WindowData m_Data;
	};
}


