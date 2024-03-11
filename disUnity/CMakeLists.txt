set(HEADER_FILES
    include/disUnity.h
    src/disUnityApplication.h
    src/Utility.h
    src/disUnityWindow.h
    src/WindowImpl.h
    src/codeGLFW/WindowGlFW.h
    
)

set(SOURCE_FILES
    src/disUnityApplication.cpp
    src/disUnityWindow.cpp
    src/codeGLFW/WindowGlFW.cpp
)



add_library(disUnity SHARED ${HEADER_FILES} ${SOURCE_FILES})


target_compile_definitions(disUnity
    PUBLIC
        $<$<CONFIG:Debug>:DISUNITY_DEBUG=2>
        $<$<CONFIG:RelWithDebInfo>:DISUNITY_DEBUG=1>
    PRIVATE
        DISUNITY_LIB
	DISUNITY_GLFW_WINDOW
)

if(MSVC)
    target_compile_definitions(disUnity PUBLIC DISUNITY_MS_COMPILER)
endif()

target_include_directories(disUnity PRIVATE ../glfw/include)
target_include_directories(disUnity PRIVATE ../disUnity)

target_precompile_headers(disUnity PRIVATE src/pch.h)

target_link_libraries(disUnity glfw)