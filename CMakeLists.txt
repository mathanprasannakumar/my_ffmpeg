cmake_minimum_required(VERSION 3.14)
project(video-app C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)


# here Extra lib is a list where we are appending the contents
list(APPEND EXTRA_LIBS "-lGL -lGLU -lX11")

add_executable(main src/main.cpp)

target_link_libraries(main glfw ${EXTRA_LIBS})



