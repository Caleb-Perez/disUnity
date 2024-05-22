#pragma once
#include "pch.h"
#include "Utility.h"
#include "Image.h"
//#include "Unit.cpp"

namespace disUnity {
	class DISUNITY_API Unit {
	public:
		Unit(const std::string& image, int x, int y);
		Unit(std::string&& image, int x, int y);

		int GetWidth() const;
		int GetHeight() const;

		int GetXCoord() const;
		int GetYCoord() const;
		void SetCoords(int x, int y);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);
	private:
		Image mImage;
		int mXPosition;
		int mYPosition;

		friend DISUNITY_API bool UnitsOverlap(const Unit& a, const Unit& b);
		friend class Renderer;
	};

	DISUNITY_API bool UnitsOverlap(const Unit& a, const Unit& b);
}
