cmake_minimum_required(VERSION 3.15)
project(Dithering)

set(OpenCV_DIR /Users/Ilia/github.com/opencv/install/lib/cmake/opencv4)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

add_executable(Dithering main.cpp camera/camera_capturing.cpp camera/camera_capturing.h)

target_link_libraries(Dithering ${OpenCV_LIBS} )

