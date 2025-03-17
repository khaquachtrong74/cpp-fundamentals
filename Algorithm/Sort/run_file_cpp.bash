#!/bin/bash

g++ -c main.cpp
g++ -c sort.cpp
g++ -c base_function.cpp

g++ main.o sort.o base_function.o -o a.out

rm *.o
