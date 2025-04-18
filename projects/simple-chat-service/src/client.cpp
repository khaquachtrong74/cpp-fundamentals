// contains `CLIENT` class - connect, send/recv

#include "../include/client.h"
#include <iostream>
void Client::SendMessage(){
    std::cout<<"Let me in!"<<std::endl;
}
void Client::Connect(){
    
}
Client::Client(std::string msg, int id) {
    this->msg = msg;
    this->id = id;
}
Client::~Client(){
    std::cout<<"Destroys success!\n";
}

