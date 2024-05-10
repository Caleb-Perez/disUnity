#pragma once

#include "pch.h"
#include "Utility.h"

constexpr int DISUNITY_FRAME_RATE{ 60 };

namespace disUnity {
	class DISUNITY_API disUnityApplication {
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();
	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::duration<int, std::chrono::milliseconds::period> mFrameDuration{ std::chrono::seconds{1} / 60/*DISUNITY_FRAME_RATE*/};
	};
}
