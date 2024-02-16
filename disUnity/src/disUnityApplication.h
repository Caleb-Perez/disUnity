#pragma once
#include "Utility.h"

namespace disUnity {
	class DISUNITY_API disUnityApplication {
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();
	private:

	};
}
