#pragma once

#include "pch.h"
#include "Utility.h"
#include "disUnityEvents.h"

constexpr int DISUNITY_FRAME_RATE{ 60 };

namespace disUnity {
	class DISUNITY_API disUnityApplication {
	public:
		disUnityApplication();

		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();
		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);
	
		void DefaultWindowCloseHandler();

	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::duration<int, std::chrono::milliseconds::period> mFrameDuration{ std::chrono::seconds{1} / 60/*DISUNITY_FRAME_RATE*/};
	
		bool mShouldContinue{ true };
	};
}
