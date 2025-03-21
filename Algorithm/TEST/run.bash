
#!/bin/bash
# Just base script to run file main
g++ -c test.cpp
g++ -c main.cpp
g++ main.o test.o -o a.out
rm *.o

