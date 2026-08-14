cmake_minimum_required(VERSION 3.16)
project(gbeam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Automatically find all C++ source files and headers in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h" "src/*.hpp")

add_executable(gbeam ${SOURCES} ${HEADERS})

target_include_directories(gbeam PRIVATE src)
target_compile_options(gbeam PRIVATE -Wall -Wextra)

