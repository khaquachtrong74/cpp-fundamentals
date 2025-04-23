#pragma once
#include <iostream>
#include <string>
#include <asio.hpp>
#include <system_error>
#include <fstream>
using asio::ip::tcp;
class Server{
    public:
        static void WriteLog(std::array<char, 128> buf, size_t len);  
        static void GetMessage(std::error_code& error, tcp::socket& socket,std::array<char, 128>&buf );
        static void SendMessage(asio::ip::tcp::socket& socket,std::string message);        
        static void SendNotification();
        static void HandleClientConnection();
        static void Resolve(std::string dmn, std::string port);
        static void TurnOnServer();
};
