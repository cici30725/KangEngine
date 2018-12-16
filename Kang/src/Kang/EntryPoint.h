#pragma once

#ifdef HZ_PLATFORM_WINDOW
	extern Kang::Application* Kang::CreateApplication();
	int main(int argc, char** argv) {
		printf("Kang's Engine");
		auto app = Kang::CreateApplication();
		app->Run();
		delete app;
	}
#endif