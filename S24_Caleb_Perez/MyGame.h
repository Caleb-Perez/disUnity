#pragma once

#include "disUnity.h"
#include "PointCounter.h"
#include "Enemies.h"
#include "Fruit.h"
#include <iostream>

class MyGame : public disUnity::disUnityApplication {
public:
	MyGame();
	virtual void Initialize() override; 

	virtual void OnUpdate() override;
	virtual void Shutdown() override;
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