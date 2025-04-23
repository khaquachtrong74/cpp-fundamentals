// contains `CLIENT` class - connect, send/recv

#include "../include/client.h"
#include <exception>
Client::Client(){}
void Client::SendMessage(asio::ip::tcp::socket& socket, std::string message){
    if(!socket.is_open()) exit(0);
    try{
        for(;;){
                std::cout<<"Send some thing to Server!\n";
                std::cout<<"User:>> ";
                getline(std::cin, message);
                asio::write(socket, asio::buffer(message));
            }
    }catch(std::exception& e){
        std::cerr<<"Error SendMessage from client: "<<e.what()<<"\n";
    }
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

