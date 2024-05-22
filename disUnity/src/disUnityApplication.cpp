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
#include "disUnityKeys.h"

namespace disUnity {
	disUnityApplication::disUnityApplication() {
		disUnityWindow::Init();
		disUnityWindow::GetWindow()->Create(1000, 800);

		Renderer::Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

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



		


		Image pic("C:/Users/Caleb/source/repos/S24_Caleb_Perez/disUnity/Assets/test.png");

		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x = 50;

		SetKeyPressedCallback([&x](const KeyPressed& event) {
			if (event.GetKeyCode() == DISUNITY_KEY_RIGHT)
				x += 50;
		});

		while (mShouldContinue) {

			Renderer::ClearScreen();

			OnUpdate();


			//x %= 800;
			Renderer::Draw(pic, x, 100);

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			disUnityWindow::GetWindow()->SwapBuffers();
			disUnityWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		disUnityWindow::ShutDown();
	}

	void disUnityApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc) {
		disUnityWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void disUnityApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc) {
		disUnityWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void disUnityApplication::SetWindowCloseCallback(std::function<void()> callbackFunc) {
		disUnityWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void disUnityApplication::DefaultWindowCloseHandler() {
		mShouldContinue = false;
	}
}

