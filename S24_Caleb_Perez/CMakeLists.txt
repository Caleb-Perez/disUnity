#set(HEADER_FILES
#	Enemies.h
#	Fruit.h
#	PointCounter.h
#)

#add_executable(Game Source.cpp)

#include_directories("../disUnity/include")

#target_link_libraries(Game disUnity)

#file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/S24_Caleb_Perez)


# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.0)

# Set the project name
project(Game)

# List of header files
set(HEADER_FILES
    Enemies.h
    Fruit.h
    PointCounter.h
)

# Source files
set(SOURCE_FILES
    Source.cpp
)

# Add executable target
add_executable(Game ${SOURCE_FILES} ${HEADER_FILES})

# Include directories
include_directories("../disUnity/include")

# Link libraries
target_link_libraries(Game disUnity)

# Copy assets to the binary directory
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/S24_Caleb_Perez)

# Organize header files into a "Header Files" filter in Visual Studio
source_group("Header Files" FILES ${HEADER_FILES})
