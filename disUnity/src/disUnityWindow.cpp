#include "pch.h"
#include "disUnityWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace disUnity {
	disUnityWindow::disUnityWindow() {
#ifdef DISUNITY_GLFW_WINDOW
		mWindow = std::make_unique<WindowGLFW>();
#else
	#definition_DISUNITY_GLFW_is_missing
#endif	
	}

	void disUnityWindow::Init() {
		if (!mInstance) {
			mInstance = new disUnityWindow;
		}
	}

	void disUnityWindow::SwapBuffers() {
		mWindow->SwapBuffers();
		
	}

	void disUnityWindow::PollEvents() {
		mWindow->PollEvents();
	}

	disUnityWindow* disUnityWindow::GetWindow() {
		return mInstance;
	}

	void disUnityWindow::Create(int width, int height) {
		mWindow->Create(width, height);
	}

	int disUnityWindow::GetWidth() const {
		return mWindow->GetWidth();
	}

	int disUnityWindow::GetHeight() const {
		return mWindow->GetHeight();
	}

	void disUnityWindow::ShutDown() {
		delete mInstance;
	}
} 