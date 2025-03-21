#!/bin/bash

g++ -c search.cpp
g++ -c main.cpp
g++ -c ../Sort/sort.cpp
g++ main.o search.o sort.o -o a.out


rm *.o
