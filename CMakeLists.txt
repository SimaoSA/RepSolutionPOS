cmake_minimum_required(VERSION 3.10)

# Name
project(POS)

# Version C++
set(CMAKE_CXX_STANDARD 14)

# Add header files folders
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/Article)
include_directories(${CMAKE_SOURCE_DIR}/include/Payments)
include_directories(${CMAKE_SOURCE_DIR}/include/SystemPOS)


# --- Add Files .cpp
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp" )


# --- Add files .hpp
file(GLOB_RECURSE HEADERS
    "${CMAKE_SOURCE_DIR}/include/*.hpp")


# -- Add Exe
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

