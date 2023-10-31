cmake_minimum_required(VERSION 3.25)

add_subdirectory(./lib/googletest/)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SORUCE_DIR})

set(TEST_SOURCE_FILES RunAllTests.cpp ProductTest.cpp ShoppingListTest.cpp UserTest.cpp ObserverTest.cpp)
add_executable(runAllTest ${TEST_SOURCE_FILES})
target_link_libraries(runAllTest gtest gtest_main core)