cmake_minimum_required(VERSION 3.12)
project(algoplus)

set(CMAKE_CXX_STANDARD 17)
file(GLOB include_all "*.h")
# Specify header-only library
add_library(algoplus INTERFACE src/include/algoplus.h)

# Include directories
target_include_directories(algoplus
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>
)

target_link_libraries(algoplus PUBLIC )

# Optionally, you can install the headers
install(DIRECTORY src/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)
