#!/usr/bin/env bash

clang-format -i --verbose --style=Google \
  ./*.cpp \
  Arrays/*/* \
  Bit/*/* \
  DynamicArray/* \
  Queue/* \
  Search/*/* \
  Sort/*/* \
  Stack/*
