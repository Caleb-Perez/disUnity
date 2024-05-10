#include "pch.h"
#include "Shader.h"

namespace disUnity {
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile) {
#ifdef DISUNITY_OPENGL
		mImplementation = std::make_unique <ShaderOpenGL>(vertexFile, fragmentFile);
#else
	#only_openGL_is_supported_so_far
#endif
	}

	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile) {
#ifdef DISUNITY_OPENGL
		mImplementation = std::make_unique <ShaderOpenGL>(std::move(vertexFile), std::move(fragmentFile));
#else
		#only_openGL_is_supported_so_far
#endif
	}

	void Shader::Bind() {
		mImplementation->Bind();
	}

	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2) {
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}
	void Shader::SetUniform2Ints(std::string&& uniformName, int val1, int val2) {
		mImplementation->SetUniform2Ints(std::move(uniformName), val1, val2);
	}
}