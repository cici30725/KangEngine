#pragma once
#include "hzpch.h"
#include "Kang/Events/Event.h"


namespace Kang {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Kang Engine", unsigned int width = 1080, unsigned int height = 720)
			:Title(title),Width(width),Height(height){}
	};

	// Window Interface
	class HAZEL_API Window {
	public:
		using EventCallbackFnc = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void OnUpdate() = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFnc& func) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		
		static Window* Create(const WindowProps& props = WindowProps());
	};
}