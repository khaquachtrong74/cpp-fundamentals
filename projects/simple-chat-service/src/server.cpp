// contains `SERVER` class-bind, listen, accept, send/recv

#include "../include/server.h"
void Server::WriteLog(std::array<char, 128> buf, size_t len){
    std::ofstream logStream("../log/server_log.txt", std::ios::app);
    if(len == 0 ) return;
    if(logStream.is_open()){
        //std::cout<<"Save ok!";
        logStream.write(buf.data(), len);
        logStream<<'\n'; logStream.close();
    }
}
void Server::GetMessage(std::error_code& error, tcp::socket& socket, std::array<char, 128>&buf){
    try{
    }catch(std::exception& e){
        std::cerr<<"Error GetMessage from Server: "<<e.what()<<"\n"; 
    }
}
void Server::SendMessage(asio::ip::tcp::socket& socket,std::string message){
//    asio::write(socketm asio
}
void Server::HandleClientConnection(){
    
}
void Server::SendNotification(){
    
}
void Server::Resolve(std::string dmn, std::string port){
    asio::io_context iso;
    asio::ip::tcp::resolver resolver(iso);
    auto endpoints = resolver.resolve(dmn, port);
    for(auto& ep : endpoints)
        std::cout<<ep.endpoint()<<"\n";
}
void Server::TurnOnServer(){
    try{
        asio::io_context iso_context;
        tcp::acceptor acceptor(iso_context, tcp::endpoint(tcp::v4(), 8080));
        std::cout<<"Server listening on port 8080...\n";
        tcp::socket socket1(iso_context);
        std::cout<<"Waiting for Client1...\n";
        acceptor.accept(socket1);
        std::cout << "Client 1 connected: " << socket1.remote_endpoint() << "\n";
        tcp::socket socket2(iso_context);
        std::cout<<"Waiting for Client2...\n";
        acceptor.accept(socket2);
        std::cout << "Client 2 connected: " << socket2.remote_endpoint() << "\n";
        std::cout<<"Chatting Room serve!\n";
        for(;;){
            std::array<char, 128> buf1, buf2;
            std::error_code err1, err2;

            // Read from client 1
            size_t lenBuf1 = socket1.read_some(asio::buffer(buf1), err1);
            if (!err1 && lenBuf1 > 0) {
                std::string mssg1(buf1.data(), lenBuf1);
                std::cout << "Client 1: " << mssg1 << '\n';
                WriteLog(buf1, lenBuf1);
            } else if (err1) {
                std::cerr << "[Client 1] Error: " << err1.message() << "\n";
            }

            // Read from client 2
            size_t lenBuf2 = socket2.read_some(asio::buffer(buf2), err2);
            if (!err2 && lenBuf2 > 0) {
                std::string mssg2(buf2.data(), lenBuf2);
                std::cout << "Client 2: " << mssg2 << '\n';
                WriteLog(buf2, lenBuf2);
            } else if (err2) {
                std::cerr << "[Client 2] Error: " << err2.message() << "\n";
            }
        }
    }catch(std::exception& e){
        std::cerr <<"Server error: "<< e.what()<<"\n";
    }
}
