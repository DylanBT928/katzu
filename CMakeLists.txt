cmake_minimum_required(VERSION 3.24)
project(katzu LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_STATIC_PIC ON CACHE BOOL "" FORCE)

add_subdirectory(dependencies/SDL)
add_subdirectory(dependencies/glm)
add_library(glad STATIC dependencies/glad/src/glad.c)
target_include_directories(glad PUBLIC dependencies/glad/include)

add_subdirectory(engine)
add_subdirectory(testbed)
