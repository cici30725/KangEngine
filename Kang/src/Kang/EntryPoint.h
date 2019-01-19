#pragma once

#ifdef HZ_PLATFORM_WINDOW
	extern Kang::Application* Kang::CreateApplication();
	int main(int argc, char** argv) {
		Kang::Log::Init();
		HZ_CORE_WARN("Initialized Logger!");
		HZ_INFO("Hello!");
		auto app = Kang::CreateApplication();
		app->Run();
		delete app;
	}
#endif