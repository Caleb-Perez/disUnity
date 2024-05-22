#pragma once

#include "pch.h"
#include "Utility.h"

namespace disUnity {
	class DISUNITY_API KeyPressed {
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class DISUNITY_API KeyReleased {
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
}