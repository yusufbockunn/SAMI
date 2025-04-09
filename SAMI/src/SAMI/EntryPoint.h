#pragma once

#ifdef SM_PLATFORM_WINDOWS


extern SAMI::Application* SAMI::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to SAMI Engine");
	auto app = SAMI::CreateApplication();
	app->Run();
	delete app;
}

#endif