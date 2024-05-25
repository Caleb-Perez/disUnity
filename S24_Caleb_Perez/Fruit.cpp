#include "Fruit.h"

Fruit::Fruit() :
	mFruit{ "Assets/Fruit.png", 0, 0 }
	{}

void Fruit::GenerateFruit(const disUnity::Unit& character, const Enemies& enemies) {
	do {
		mFruit.SetCoords(rand() % 20 * 50, rand() % 16 * 50);
	} while (enemies.FruitOverlaps(mFruit));
}

bool Fruit::EatsFruit(const disUnity::Unit& character) const {
	return disUnity::UnitsOverlap(character, mFruit);
}

void Fruit::DrawFruit() {
	disUnity::Renderer::Draw(mFruit);
}