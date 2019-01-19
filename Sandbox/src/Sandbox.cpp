#include <Kang.h>
class ExampleLayer : public Kang::Layer {
public:
	ExampleLayer()
		:Layer("example"){}
	void OnUpdate() override {
		//HZ_TRACE("ExampleLayer::Update");
	}

	void OnEvent(Kang::Event& event) override {
		HZ_TRACE(event.ToString());
	}
};

class Sandbox : public Kang::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverLay(new Kang::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Kang::Application* Kang::CreateApplication() {
	return new Sandbox();
}