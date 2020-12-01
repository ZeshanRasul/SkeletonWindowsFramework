#include "Application.h"
#include <assert.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application* Application::s_Instance = nullptr;

Application::Application()
{
	assert(!s_Instance);
	s_Instance = this;

	// Create window
	// Set window callback
};

Application::~Application()
{

}

int Application::Run()
{
	while (m_Running)
	{

	}

	return 0;
}

void Application::OnEvent(Event& event)
{

}
