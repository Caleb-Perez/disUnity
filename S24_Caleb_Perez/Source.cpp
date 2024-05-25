#include "disUnity.h"
#include <iostream>
#include "PointCounter.h"
#include "Enemies.h"
#include "Fruit.h"

class MyGame : public disUnity::disUnityApplication {
public:
	MyGame() : 
		mBackground{ "Assets/Background.png", 0, 0 }, 
		mCharacterUp{ "Assets/CharacterUp.png", 0, 0 },	
		mCharacterRight{ "Assets/CharacterRight.png", 0, 0 },
		mCharacterDown{ "Assets/CharacterDown.png", 0, 0 }, 
		mCharacterLeft{ "Assets/CharacterLeft.png", 0, 0 }, 
		mCurrCharacter { &mCharacterRight }
	{}

	virtual void Initialize() override {
		//Init button press functions
		SetKeyPressedCallback([&](const disUnity::KeyPressed& e) {
			if (e.GetKeyCode() == DISUNITY_KEY_UP || e.GetKeyCode() == DISUNITY_KEY_W) {
				if (mCurrCharacter->GetYCoord() <= 700) {
					mCharacterUp.SetCoords(mCurrCharacter->GetXCoord(), mCurrCharacter->GetYCoord() + 50);
				}else{
					mCharacterUp.SetCoords(mCurrCharacter->GetXCoord(), 750);
				}
				mCurrCharacter = &mCharacterUp;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_RIGHT || e.GetKeyCode() == DISUNITY_KEY_D) {
				if (mCurrCharacter->GetXCoord() <= 900) {
					mCharacterRight.SetCoords(mCurrCharacter->GetXCoord() + 50, mCurrCharacter->GetYCoord());
				}else {
					mCharacterRight.SetCoords(950, mCurrCharacter->GetYCoord());
				}
				mCurrCharacter = &mCharacterRight;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_DOWN || e.GetKeyCode() == DISUNITY_KEY_S) {
				if (mCurrCharacter->GetYCoord() >= 50) {
					mCharacterDown.SetCoords(mCurrCharacter->GetXCoord(), mCurrCharacter->GetYCoord() - 50);
				}else {
					mCharacterDown.SetCoords(mCurrCharacter->GetXCoord(), 0);
				}
				mCurrCharacter = &mCharacterDown;
			}

			if (e.GetKeyCode() == DISUNITY_KEY_LEFT || e.GetKeyCode() == DISUNITY_KEY_A) {
				if (mCurrCharacter->GetXCoord() >= 50) {
					mCharacterLeft.SetCoords(mCurrCharacter->GetXCoord() - 50, mCurrCharacter->GetYCoord());
				}else {
					mCharacterLeft.SetCoords(0, mCurrCharacter->GetYCoord());
				}
				mCurrCharacter = &mCharacterLeft;
			}
		});


		//Init entities
		mCurrCharacter->SetCoords(500, 400);
		mEnemies.Reset(*mCurrCharacter);
		mFruit.GenerateFruit(*mCurrCharacter, mEnemies);
	}

	virtual void OnUpdate() override {
		//Hit a ghost
		if (mEnemies.TakesDamage(*mCurrCharacter)) {
			mCurrCharacter = &mCharacterRight;
			mCurrCharacter->SetCoords(500, 400);
			mPoints.PointsReset();
			mEnemies.Reset(*mCurrCharacter);
			mFruit.GenerateFruit(*mCurrCharacter, mEnemies);
		}

		//Hit a fruit
		if (mFruit.EatsFruit(*mCurrCharacter)) {
			mEnemies.LevelUp(*mCurrCharacter);
			mFruit.GenerateFruit(*mCurrCharacter, mEnemies);
			mPoints.IncrementPoints();
		}
	
		//Drawing
		disUnity::Renderer::Draw(mBackground);
		disUnity::Renderer::Draw(*mCurrCharacter);
		mEnemies.DrawEnemies();
		mFruit.DrawFruit();
		mPoints.DrawPoints();
	}

	virtual void Shutdown() override {}

private:
	//Character and Background
	disUnity::Unit mBackground;
	disUnity::Unit* mCurrCharacter;
	disUnity::Unit mCharacterUp;
	disUnity::Unit mCharacterRight;
	disUnity::Unit mCharacterDown;
	disUnity::Unit mCharacterLeft;

	//Other on-screen entities
	Enemies mEnemies;
	Fruit mFruit;
	PointCounter mPoints;

};

START_GAME(MyGame);
