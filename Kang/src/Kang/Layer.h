#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Kang {
	class HAZEL_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		~Layer();
		virtual void OnAttach() {}
		virtual void OnDettach() {}
		virtual void OnEvent(Event& event) {}
		virtual void OnUpdate() {}
	private:
		std::string m_DebugName;
	};
}

