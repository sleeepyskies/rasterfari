cmake_minimum_required (VERSION 3.5)
project(rasterfari)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# dependencies
include_directories(${CMAKE_SOURCE_DIR}/include)
set(SDL2_DIR "D:/dev/useful_libs/SDL2-2.30.9/cmake")
find_package(SDL2 REQUIRED)
link_directories(${CMAKE_SOURCE_DIR}/libs)

find_package(OpenMP)
if(OPENMP_FOUND)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

file(GLOB SOURCES src/*.h src/*.cpp)
# Include headers from src and src/geometry recursively (if needed)
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/src/*.hpp)
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/geometry)
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/math)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link SDL2 dynamically
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)