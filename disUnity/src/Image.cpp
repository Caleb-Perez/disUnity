#include "pch.h"
#include "Image.h"
#include "codeOpenGL/ImageOpenGL.h"

namespace disUnity {
	Image::Image(const std::string& filePath) {
#ifdef DISUNITY_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>(filePath);
#else
		#only_openGL_is_supported_so_far
#endif

	}

	Image::Image(std::string&& filePath) {
#ifdef DISUNITY_OPENGL
		mImplementation = std::make_unique<ImageOpenGL>(std::move(filePath));
#else
		#only_openGL_is_supported_so_far
#endif

	}

	int Image::GetWidth() const {
		return mImplementation->GetWidth();
	}

	int Image::GetHeight() const {
		return mImplementation->GetHeight();
	}

	void Image::Bind() {
		mImplementation->Bind();
	}
}