#include "pch.h"
#include "disUnityApplication.h"

namespace disUnity {

}

void disUnity::disUnityApplication::Initialize()
{
}

void disUnity::disUnityApplication::OnUpdate()
{
}

void disUnity::disUnityApplication::Shutdown()
{
}

void disUnity::disUnityApplication::Run() {
	Initialize();

	while (true) {
		OnUpdate();
	}
	
	Shutdown();
}