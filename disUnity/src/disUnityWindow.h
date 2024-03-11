#pragma once

#include"pch.h"
#include "WindowImpl.h"
#include "Utility.h"

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
	private: 
		inline static disUnityWindow* mInstance{ nullptr };
		std::unique_ptr<WindowImpl> mWindow{nullptr};

		disUnityWindow();
	};
}