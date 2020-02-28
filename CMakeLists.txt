cmake_minimum_required(VERSION 3.5)

project(carsStream LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)
set(SOURCES
    src/Cars.cpp
    src/Geometry.cpp
)
set(HEADERS
    include/Cars.h
    include/Geometry.h
)
add_executable(${PROJECT_NAME} "main.cpp" ${SOURCES} ${HEADERS})
