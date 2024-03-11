#include "pch.h"
#include "disUnityApplication.h"
#include "disUnityWindow.h"
#include "GLFW/glfw3.h"

namespace disUnity {

}

void disUnity::disUnityApplication::Initialize()
{
}

void disUnity::disUnityApplication::OnUpdate()
{
}

void disUnity::disUnityApplication::Shutdown()
{
}

void disUnity::disUnityApplication::Run() {
	disUnityWindow::Init();
	disUnityWindow::GetWindow()->Create(1000, 800);
	Initialize();

	while (true) {

		OnUpdate();

		disUnityWindow::GetWindow()->SwapBuffers();
		disUnityWindow::GetWindow()->PollEvents();
	}
	
	Shutdown();

	disUnityWindow::ShutDown();
}