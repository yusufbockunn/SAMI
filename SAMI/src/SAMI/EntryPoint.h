#pragma once

#ifdef SM_PLATFORM_WINDOWS


extern SAMI::Application* SAMI::CreateApplication();

int main(int argc, char** argv)
{

	SAMI::Log::Init();
	SM_ENGINE_WARN("TEST CASE ENGINE WARN!\n");
	SM_INFO("TEST CASE CLIENT INFO!\n");


	
	auto app = SAMI::CreateApplication();
	app->Run();
	delete app;
}

#endif