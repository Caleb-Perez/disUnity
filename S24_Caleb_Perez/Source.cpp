#include "disUnity.h"
#include <iostream>

class MyGame : public disUnity::disUnityApplication {
	virtual void OnUpdate() override {
		std::cout << "engine is running" << std::endl;
	}
};

START_GAME(MyGame);
