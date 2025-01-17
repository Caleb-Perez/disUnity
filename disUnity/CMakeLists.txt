set(HEADER_FILES
	include/disUnity.h
	src/disUnityApplication.h
	src/Utility.h
	src/disUnityWindow.h
	src/WindowImpl.h
	src/codeGLFW/WindowGlFW.h
	src/Renderer.h
	src/RendererImplement.h
	src/codeOpenGL/RendererOpenGL.h
	src/Shader.h
	src/ShaderImplement.h
	src/codeOpenGL/ShaderOpenGL.h
	src/Image.h
	src/ImageImplement.h
	src/codeOpenGL/ImageOpenGL.h
	src/disUnityEvents.h
	src/disUnityKeys.h
	src/Unit.h    
)

set(SOURCE_FILES
	src/disUnityApplication.cpp
	src/disUnityWindow.cpp
	src/codeGLFW/WindowGLFW.cpp
	src/Renderer.cpp
	src/codeOpenGL/RendererOpenGL.cpp
	src/Shader.cpp
	src/codeOpenGL/ShaderOpenGL.cpp
	src/Image.cpp
	src/codeOpenGL/ImageOpenGL.cpp
	src/disUnityEvents.cpp
	src/Unit.cpp
)



add_library(disUnity SHARED ${HEADER_FILES} ${SOURCE_FILES})


target_compile_definitions(disUnity
    PUBLIC
        $<$<CONFIG:Debug>:DISUNITY_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:DISUNITY_DEBUG=1>
    PRIVATE
        DISUNITY_LIB
	DISUNITY_GLFW_WINDOW
	DISUNITY_OPENGL
)

if(MSVC)
    target_compile_definitions(disUnity PUBLIC DISUNITY_MS_COMPILER)
endif()

target_include_directories(disUnity PRIVATE ../glfw/include)
target_include_directories(disUnity PRIVATE ../disUnity/src)
target_include_directories(disUnity PRIVATE ../glad/include)
target_include_directories(disUnity PRIVATE ../stbi)

target_precompile_headers(disUnity PRIVATE src/pch.h)

target_link_libraries(disUnity glfw)
target_link_libraries(disUnity glad)
target_link_libraries(disUnity stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/disUnity)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug/disUnity)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release/disUnity)