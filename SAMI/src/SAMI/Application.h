#pragma once
#include "Core.h"


namespace SAMI
{

	class SAMI_API Application
	{
	public:


		Application();
		virtual~Application();
		void Run();
	};

	Application* CreateApplication();

}


