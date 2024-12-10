cmake_minimum_required (VERSION 3.3)
project(Rasterfari)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# include src files
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/libs)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES src/*.h src/*.cpp)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/src/*.hpp)
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/geometry)
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/math)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Manually specify SDL2 include directory and libraries
set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include/sdl2")
set(SDL2_LIBRARIES "${CMAKE_SOURCE_DIR}/libs/libSDL2.a;${CMAKE_SOURCE_DIR}/libs/libSDL2main.a")

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIR})

# Define static linking settings
# add_definitions(-DSDL_MAIN_HANDLED)

# Link SDL2 statically
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

message("SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
