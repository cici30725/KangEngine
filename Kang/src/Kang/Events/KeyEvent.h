#pragma once
#include "Event.h"

namespace Kang {
	class HAZEL_API KeyEvent : public Event {
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)
	protected:
		KeyEvent(int code)
			:m_KeyCode(code){}
		int m_KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatedTimes)
			:KeyEvent(keycode), m_repeatedTimes(repeatedTimes){}

		/* Need to Macro these three functions below */
		EVENT_CLASS_TYPE(KeyPressed)
		 std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressed Event : " << m_KeyCode << "(" << m_repeatedTimes << "repeats)";
			return ss.str();
		}
	protected:
		int m_repeatedTimes = 0;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode){}

		EVENT_CLASS_TYPE(KeyReleased)
		
	};

}