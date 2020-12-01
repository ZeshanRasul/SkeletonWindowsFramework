#pragma once

class Application
{
public:
	Application();
	virtual ~Application();

	int Run();
	
	// void OnEvent(Event& event);

	inline static Application& Get() { return *s_Instance; }

	//inline Window& GetWindow() { return *m_Window; }


private:
	bool m_Running = true;
	//void OnWindowClose(WindowCloseEvent& event);

	//std::unique_ptr<Window> m_Window;
	static Application* s_Instance;
};
