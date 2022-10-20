# Algorithms written in C++

## How to create build directory

cmake -B ./cmake-build-debug -S. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

## How to build

cmake --build cmake-build-debug/

## Coverage

lcov -t "TestsCoverage" -o coverage.info -c -d cmake-build-debug/Tests/CMakeFiles/Tests.dir/__/

## HTML result

genhtml -o report coverage.info

## Memory test

valgrind --tool=memcheck --leak-check=yes ./a.out

## Sanitizers

g++ -fsanitize=address,undefined,leak -fno-sanitize-recover=all -fsanitize-undefined-trap-on-error -c <source>
