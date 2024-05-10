#include "pch.h"
#include "disUnityApplication.h"
#include "disUnityWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "codeOpenGL/ImageOpenGL.h"
#include "Renderer.h"
#include "Image.h"
#include "Shader.h"

namespace disUnity {
	void disUnityApplication::Initialize()
	{
	}

	void disUnityApplication::OnUpdate()
	{
	}

	void disUnityApplication::Shutdown()
	{
	}

	void disUnityApplication::Run() {

		disUnityWindow::Init();
		disUnityWindow::GetWindow()->Create(1000, 800);
		Renderer::Init();



		Shader sProg{ "C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/Shaders/DefaultVertexShader", "C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/Shaders/DefaultFragmentShader" };



		Image pic("C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/test.png");

		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x = 50;

		while (true) {

			Renderer::ClearScreen();

			OnUpdate();



			Renderer::Draw(pic, x, 100);
			//x += 2;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			disUnityWindow::GetWindow()->SwapBuffers();
			disUnityWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		disUnityWindow::ShutDown();
	}
}

