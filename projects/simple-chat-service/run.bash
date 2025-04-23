#!/bin/bash

PWD=$(pwd)
cd ~/cpp-fundamentals/projects/simple-chat-service/build/ 
make
#./client localhost
#./server
cd "$PWD"
