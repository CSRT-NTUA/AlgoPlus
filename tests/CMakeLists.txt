file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/tests/*.cc"
        "${CMAKE_SOURCE_DIR}/tests/test_main.cc")

add_executable(runUnitTests ${TEST_SOURCES})

target_link_libraries(runUnitTests PUBLIC ${CMAKE_DL_LIBS})

# Include the directory with header files
target_include_directories(runUnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/algorithms)
target_include_directories(runUnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/classes)
target_include_directories(runUnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/linalg)
target_include_directories(runUnitTests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src/machine_learning)

enable_testing()

add_test(NAME runUnitTests COMMAND runUnitTests)
