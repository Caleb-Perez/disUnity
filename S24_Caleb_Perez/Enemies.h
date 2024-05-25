#pragma once
#include "disUnity.h"

class Enemies {
public:
	Enemies();
	void Reset(const disUnity::Unit& character);
	void LevelUp(const disUnity::Unit& character);
	bool TakesDamage(const disUnity::Unit& character);
	bool FruitOverlaps(const disUnity::Unit& fruit) const;
	void DrawEnemies();
private:
	void GenerateEnemies(const disUnity::Unit& character);

	std::string mEnemyImage;
	std::vector<disUnity::Unit> mEnemies;
	int mEnemyCount;
};