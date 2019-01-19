#pragma once
#include "Kang/Layer.h"

namespace Kang {
	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach() override;
		void OnDettach() override;
		void OnEvent(Event& event) override;
		void OnUpdate() override;
	private:
		float m_Time = 0.0f;
	};
}


