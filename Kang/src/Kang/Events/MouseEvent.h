#pragma once
#include "Event.h"

namespace Kang {
	class HAZEL_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(int x, int y):m_MouseX(x),m_MouseY(y){}
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << "(" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX;
		float m_MouseY;
	};
	
	class HAZEL_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(float x, float y)
			:m_XOffset(x),m_YOffset(y){}
		inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrollEvent:" << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset;
		float m_YOffset;
	};

	class HAZEL_API MouseButtonEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		inline int GetMouseButton() { return m_Button; }
	protected:
		MouseButtonEvent(int button):m_Button(button){}
		int m_Button;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button){}
		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "MousePressed: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button){}
		virtual std::string ToString() const override{
			std::stringstream ss;
			ss << "MouseReleased: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}