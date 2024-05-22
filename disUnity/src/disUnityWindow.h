#pragma once

#include"pch.h"
#include "WindowImpl.h"
#include "Utility.h"
#include "disUnityEvents.h"

namespace disUnity {
	class DISUNITY_API disUnityWindow {
	public:
		static void Init();
		static disUnityWindow* GetWindow();
		static void ShutDown();

		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

	private: 
		inline static disUnityWindow* mInstance{ nullptr };
		std::unique_ptr<WindowImpl> mWindow{nullptr};

		disUnityWindow();
	};
}