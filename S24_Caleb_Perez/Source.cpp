#include "disUnity.h"
#include <iostream>

class MyGame : public disUnity::disUnityApplication {
public:
	MyGame() : 
		mBackground{ "Assets/Background.png", 0, 0 }, 
		mCharacterUp{ "Assets/CharacterUp.png", 0, 0 },	
		mCharacterRight{ "Assets/CharacterRight.png", 0, 0 },
		mCharacterDown{ "Assets/CharacterDown.png", 0, 0 }, 
		mCharacterLeft{ "Assets/CharacterLeft.png", 0, 0 }, mCurrCharacter { &mCharacterRight } {
	}

	virtual void Initialize() override {
		SetKeyPressedCallback([&](const disUnity::KeyPressed& e) {
			if (e.GetKeyCode() == DISUNITY_KEY_UP || e.GetKeyCode() == DISUNITY_KEY_W) {
				mCharacterUp.SetCoords(mCurrCharacter->GetXCoord(), mCurrCharacter->GetYCoord() + 50);
				mCurrCharacter = &mCharacterUp;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_RIGHT || e.GetKeyCode() == DISUNITY_KEY_D) {
				mCharacterRight.SetCoords(mCurrCharacter->GetXCoord() + 50, mCurrCharacter->GetYCoord());
				mCurrCharacter = &mCharacterRight;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_DOWN || e.GetKeyCode() == DISUNITY_KEY_S) {
				mCharacterDown.SetCoords(mCurrCharacter->GetXCoord(), mCurrCharacter->GetYCoord() - 50);
				mCurrCharacter = &mCharacterDown;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_LEFT || e.GetKeyCode() == DISUNITY_KEY_A) {
				mCharacterLeft.SetCoords(mCurrCharacter->GetXCoord() - 50, mCurrCharacter->GetYCoord());
				mCurrCharacter = &mCharacterLeft;
			}
		});

		mCurrCharacter->SetCoords(500, 400);
	}

	virtual void OnUpdate() override {
		//Work on Edges
		/**
		if (mCurrCharacter->GetXCoord() < 0) {
			mCurrCharacter->SetCoords(1000, mCurrCharacter->GetYCoord());
		}
		else if (mCurrCharacter->GetXCoord() >= 1000) {
			mCurrCharacter->SetCoords(0, mCurrCharacter->GetYCoord());
		}*/
	//		|| mCurrCharacter->GetYCoord() < 0 || mCurrCharacter->GetYCoord() > 800) {
		//}


		disUnity::Renderer::Draw(mBackground);
		disUnity::Renderer::Draw(*mCurrCharacter);


	}

	virtual void Shutdown() override {
		mCurrCharacter = nullptr;
	}

private:
	disUnity::Unit mBackground;
	disUnity::Unit* mCurrCharacter;
	disUnity::Unit mCharacterUp;
	disUnity::Unit mCharacterRight;
	disUnity::Unit mCharacterDown;
	disUnity::Unit mCharacterLeft;

};

START_GAME(MyGame);
