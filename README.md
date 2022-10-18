# Algorithms written in C++

## How to create build directory

cmake -B ./cmake-build-debug -S. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

## How to build

cmake --build cmake-build-debug/

## Coverage (in dir cmake-build-debug)

lcov -t "Tests coverage" -o coverage.info -c -d Tests/CMakeFiles/Tests.dir/__/

## HTML result

genhtml -o report coverage.info
