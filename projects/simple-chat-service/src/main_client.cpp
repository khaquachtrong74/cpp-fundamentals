#include "../include/client.h"
#include <system_error>
using asio::ip::tcp;
int main(int argc, char* argv[]){
    Client user;
    try{
        if(argc != 3){
            std::cerr<<"Usage: Client <host>"<<std::endl;
            return 1;
        }
        asio::io_context io_context;
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(argv[1], argv[2]);
        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);
        std::cout<<"Connect to Server\n";
        user.SendMessage(socket, ""); 
    }catch(const std::exception& e){
        std::cerr << "Error: "<< e.what()<<"\n";
    }  
    return 0;
}
