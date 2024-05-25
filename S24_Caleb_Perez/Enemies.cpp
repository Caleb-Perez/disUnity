#include "Enemies.h"

Enemies::Enemies() :
	mEnemyImage{ "Assets/Enemy.png" },
	mEnemyCount{ 10 }
	{}

void Enemies::Reset(const disUnity::Unit& character) {
	mEnemyCount = 10;
	GenerateEnemies(character);
}

void Enemies::LevelUp(const disUnity::Unit& character) {
	mEnemyCount += 2;
	GenerateEnemies(character);
}

bool Enemies::TakesDamage(const disUnity::Unit& character) {
	for (const disUnity::Unit& enemy : mEnemies) {
		if (disUnity::UnitsOverlap(character, enemy)) {
			mEnemies.clear();
			mEnemyCount = 10;
			return true;
		}
	}
	return false;
}

bool Enemies::FruitOverlaps(const disUnity::Unit& fruit) const {
	for (const disUnity::Unit& enemy : mEnemies) {
		if (disUnity::UnitsOverlap(fruit, enemy)) {
			return true;
		}
	}
	return false;
}

void Enemies::DrawEnemies() {
	for (disUnity::Unit& enemy : mEnemies) {
		disUnity::Renderer::Draw(enemy);
	}
}

void Enemies::GenerateEnemies(const disUnity::Unit& character) {
	mEnemies.clear();
	while (mEnemies.size() < mEnemyCount) {
		disUnity::Unit newEnemy(mEnemyImage, rand() % 20 * 50, rand() % 16 * 50);
		if (!disUnity::UnitsOverlap(newEnemy, character))
			mEnemies.push_back(std::move(newEnemy));
	}
}