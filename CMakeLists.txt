cmake_minimum_required(VERSION 2.8)
project(ece650-a2)

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# create the main executable
## add additional .cpp files if needed
add_executable(calc main.cpp calc.cpp)

# create the executable for tests
enable_testing()
add_executable(tests test.cpp calc.cpp)
add_test(NAME CalcTests COMMAND tests)

# make ctest show errors upon test failure
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure DEPENDS tests)