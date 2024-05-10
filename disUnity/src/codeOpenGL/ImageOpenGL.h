#pragma once
#include "pch.h"
#include "../ImageImplement.h"

namespace disUnity {
	class ImageOpenGL : public ImageImplement {
	public:
		ImageOpenGL(const std::string& filePath);
		ImageOpenGL(const std::string&& filePath);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() const override;
		virtual ~ImageOpenGL();
		
	private:
		unsigned int mTexture{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
	
}