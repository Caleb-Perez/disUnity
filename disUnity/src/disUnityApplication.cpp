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

		SetWindowCloseCallback([this]() { DefaultWindowCloseHandler(); });
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

		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;


		while (mShouldContinue) {

			Renderer::ClearScreen();

			OnUpdate();

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

