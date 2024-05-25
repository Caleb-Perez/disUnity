#pragma once
#include "disUnity.h"
#include "Enemies.h"

class Fruit {
public:
	Fruit() : 
		mFruit{"Assets/Fruit.png", 0, 0}
	{}

	void GenerateFruit(const disUnity::Unit& character, const Enemies& enemies) {
		do {
			mFruit.SetCoords(rand() % 20 * 50, rand() % 16 * 50);
		} while (enemies.FruitOverlaps(mFruit));
	}

	bool EatsFruit(const disUnity::Unit& character) {
		return disUnity::UnitsOverlap(character, mFruit);
	}

	void DrawFruit(){
		disUnity::Renderer::Draw(mFruit);
	}
private:
	disUnity::Unit mFruit;
};