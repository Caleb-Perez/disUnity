add_executable(Game Source.cpp)

include_directories("../disUnity/include")

target_link_libraries(Game disUnity)
