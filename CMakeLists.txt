cmake_minimum_required(VERSION 4.0)
project(Mini_STL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include folder for headers
# Include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source grouping
file(GLOB_RECURSE VECTOR_SRC "src/Vector/*.cpp")

# Include folder (root include path)
add_library(vector ${VECTOR_SRC})
target_include_directories(vector PUBLIC include)

add_executable(Mini_STL test/main.cpp)

target_link_libraries(Mini_STL PRIVATE vector)