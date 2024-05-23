add_executable(Game Source.cpp)

include_directories("../disUnity/include")

target_link_libraries(Game disUnity)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/S24_Caleb_Perez)