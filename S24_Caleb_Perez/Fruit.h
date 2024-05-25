#pragma once
#include "disUnity.h"
#include "Enemies.h"

class Fruit {
public:
	Fruit();
	void GenerateFruit(const disUnity::Unit& character, const Enemies& enemies);
	bool EatsFruit(const disUnity::Unit& character) const;
	void DrawFruit();
private:
	disUnity::Unit mFruit;
};