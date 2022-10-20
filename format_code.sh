#!/usr/bin/env bash

clang-format -i --verbose -style=file:".clang-format" \
  ./*.cpp \
  Arrays/*/* \
  Bit/*/* \
  DynamicArray/* \
  Queue/* \
  Search/*/* \
  Sort/*/* \
  Stack/* \
  Heap/*
