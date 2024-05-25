#pragma once
#include "PointCounter.h"

PointCounter::PointCounter() {
	for (int i = 0; i < 10; i++) {
		mNumberImages.push_back(disUnity::Image("Assets/Numbers/" + std::to_string(i) + ".png"));
	}
}

void PointCounter::PointsReset() {
	mPoints = 0;
}

void PointCounter::IncrementPoints() {
	mPoints++;
}

void PointCounter::DrawPoints() {
	if (!mPoints) {
		disUnity::Renderer::Draw(mNumberImages[0], 900, 700);
		return;
	}
	int points = mPoints;
	int digit_count = 0;
	while (points) {
		int curr_digit = points % 10;

		disUnity::Renderer::Draw(mNumberImages[curr_digit], 900 - digit_count * 40, 700);
		digit_count++;
		points /= 10;
	}
}