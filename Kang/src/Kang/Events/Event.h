#pragma once
#include "hzpch.h"
#include "Kang/Core.h"

namespace Kang {
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

#define BIT(x) 1<<x
	enum EventCategories {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlag() const override {return category;}

	// GetStaticType is used to identify which Event it is if an Event is polymophed
	// GetEventType is used to compare two Events in the EventDispatcher
#define EVENT_CLASS_TYPE(type) virtual EventType GetEventType() const override { return GetStaticType(); }\
	static EventType GetStaticType() { return EventType::##type; }\
	virtual std::string GetName() const override { return #type; }


	class HAZEL_API Event {
		friend class EventDispatcher;
	public:
		bool Handled = false;
		virtual EventType GetEventType() const = 0;
		virtual int GetEventCategoryFlag() const = 0;
		virtual std::string GetName() const = 0;
		virtual std::string ToString()	const { return GetName(); }	/* Can be overriden to print more details */
		
		inline bool InEventCategory(EventCategories eventCatagory) {
			return eventCatagory & GetEventCategoryFlag();
		}
	};

	class HAZEL_API EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			:m_Event(e){}
		
		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}