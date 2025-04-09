#include <SAMI.h>


class Sandbox:public SAMI::Application
{
public:

	Sandbox()
	{
	}

	~Sandbox()
	{
	
	}

};




SAMI::Application* SAMI::CreateApplication()
{

	return new Sandbox();
}