cmake_minimum_required(VERSION 3.12)
project(algoplus VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(unit_name "algoplus")
set(package_name "${unit_name}")
set(package_version "0.1.0")

message(STATUS "Project '${PROJECT_NAME}', package '${package_name}' version: '${package_version}'")

file(GLOB include_all "*.h")

add_library(${package_name} INTERFACE)

target_include_directories(${package_name} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(algoplus PUBLIC )


enable_testing()

add_subdirectory(tests)