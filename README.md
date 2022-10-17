# Algorithms written in C++

## How to create build directory

cmake -B ./cmake-build-debug -S. -D CMAKE_BUILD_TYPE=Debug

## How to build

cmake --build cmake-build-debug/

## Coverage (in dir cmake-build-debug)

lcov -t "Tests coverage" -o coverage.info -c -d Tests/CMakeFiles/Tests.dir/__/

## HTML result

genhtml -o report coverage.info
