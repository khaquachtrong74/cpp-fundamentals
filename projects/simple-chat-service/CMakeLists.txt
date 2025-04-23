cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)          #model 
include_directories(include)        #include files head *.h *.hpp
# [CAN NOT] use those because in this project have 2 main function in src/
#file(GLOB SOURCES "src/*.cpp")      #search for all file *.cpp in src/ then stores their paths in a Global Variable name SOURCES
#add_executable(MyApp ${SOURCES})

# So we will sperate it into 2 
add_executable(server
    src/main_server.cpp
    src/server.cpp
)
add_executable(client
    src/main_client.cpp
    src/client.cpp
)
