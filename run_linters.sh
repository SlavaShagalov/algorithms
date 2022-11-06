#!/usr/bin/env bash

set -o pipefail

function print_header() {
  echo -e "\n***** ${1} *****"
}

function check_log() {
  LOG=$({ ${1}; } 2>&1)
  STATUS=$?
  echo "$LOG"
  if echo "$LOG" | grep -q -E "${2}"; then
    exit 1
  fi

  if [ $STATUS -ne 0 ]; then
    exit $STATUS
  fi
}

print_header "RUN cppcheck"
check_log "cppcheck . \
                    -D__cplusplus \
                    --check-config \
                    --enable=all \
                    --inconclusive \
                    --error-exitcode=1 \
                    -I Arrays/* \
                    -I Bit/* \
                    -I DynamicArray \
                    -I Queue \
                    -I Search/LinearSearch \
                    -I Search/BinarySearch \
                    -I Sort/QuickSort \
                    -I Sort/BubbleSort \
                    -I Sort/MergeSort \
                    -I Sort/BinaryMSDSort \
                    -I Heap \
                    -I Stack \
                    -I Different/KStatSearchDC \
                    -I . \
                    --config-exclude=cmake-build-debug \
                    -i cmake-build-debug \
                    --std=c11 --std=c++11 \
                    --suppress=missingIncludeSystem" "\(information\)"

print_header "RUN cpplint"
check_log "cpplint --recursive \
                   --extensions=c,cpp,h,hpp \
                   --exclude=cmake-build-debug \
                   ." "Can't open for reading"

print_header "RUN clang-tidy"
check_log "clang-tidy ./*.cpp \
                      Arrays/*/* \
                      Bit/*/* \
                      DynamicArray/* \
                      Queue/* \
                      Search/*/* \
                      Sort/*/* \
                      Stack/* \
                      -warnings-as-errors=* \
                      -extra-arg=-std=c++11 \
                      --format-style='google' \
                      --use-color \
                      -p cmake-build-debug/compile_commands.json -- \
                      -I. \
                      -I Stack \
                      -I Heap \
                      -I DynamicArray \
                      -I Queue \
                      -I Sort \
                      -I Sort/BinaryMSDSort \
                      -I Sort/BubbleSort \
                      -I Sort/MergeSort \
                      -I Search \
                      -I Search/BinarySearch" "Error (?:reading|while processing)"

print_header "SUCCESS"
