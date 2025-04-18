#pragma once
#include <string>
class Client{
    private:
        std::string msg;
        int id;
    public:
        Client(std::string msg, int id);
        ~Client();
        void Connect();
        void SendMessage();
};
