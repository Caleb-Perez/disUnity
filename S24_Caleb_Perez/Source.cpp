#include "disUnity.h"
#include <iostream>

class MyGame : public disUnity::disUnityApplication {
	virtual void Initialize() override {}

	virtual void OnUpdate() override {
		//std::cout << "window with: " << disUnity::disUnityWindow::GetWindow()->GetWidth() << std::endl;
	}
private:
};

START_GAME(MyGame);
