#pragma once
#include <string>
#include <iostream>
#include <array>
#include <asio.hpp>
#include <exception>
#include <fmt/core.h>
#include <error.h>
class Client{
    private:
        std::string msg;
        int id;
    public:
        Client(std::string msg, int id);
        Client();
        ~Client();
        void Connect();
        void SendMessage(asio::ip::tcp::socket& socket, std::string message);

};
