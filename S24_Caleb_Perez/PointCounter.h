#pragma once
#include "disUnity.h"

class PointCounter {
public:
	PointCounter();
	void PointsReset();
	void IncrementPoints();
	void DrawPoints();
private:
	int mPoints{ 0 };
	std::vector<disUnity::Image> mNumberImages;
};