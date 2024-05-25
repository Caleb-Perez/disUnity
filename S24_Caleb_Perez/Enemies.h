#pragma once
#include "disUnity.h"
#include <unordered_map>
#include <unordered_set>

class Enemies {
public:
	Enemies() :
		mEnemyImage{ "Assets/Enemy.png" },
		mEnemyCount{ 10 } 
	{}

	void Reset(const disUnity::Unit& character) {
		mEnemyCount = 10;
		GenerateEnemies(character);
	}

	void LevelUp(const disUnity::Unit& character) {
		mEnemyCount += 2;
		GenerateEnemies(character);
	}

	bool TakesDamage(const disUnity::Unit& character) {
		for (const disUnity::Unit& enemy : mEnemies) {
			if (disUnity::UnitsOverlap(character, enemy)) {
				mEnemies.clear();
				mEnemyCount = 10;
				return true;
			}
		}
		return false;
	}

	bool FruitOverlaps(const disUnity::Unit& fruit) const{
		for (const disUnity::Unit& enemy : mEnemies) {
			if (disUnity::UnitsOverlap(fruit, enemy)) {
				return true;
			}
		}
		return false;
	}

	void DrawEnemies() {
		for (disUnity::Unit& enemy : mEnemies) {
			disUnity::Renderer::Draw(enemy);
		}
	}

private:
	void GenerateEnemies(const disUnity::Unit& character) {
		mEnemies.clear();
		while (mEnemies.size() < mEnemyCount) {
			disUnity::Unit newEnemy(mEnemyImage, rand() % 20 * 50, rand() % 16 * 50);
			if (!disUnity::UnitsOverlap(newEnemy, character))
				mEnemies.push_back(std::move(newEnemy));
		}
	}

	std::string mEnemyImage;
	std::vector<disUnity::Unit> mEnemies;
	int mEnemyCount;
};