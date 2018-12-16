#include <Kang.h>
class Sandbox : public Kang::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Kang::Application* Kang::CreateApplication() {
	return new Sandbox();
}