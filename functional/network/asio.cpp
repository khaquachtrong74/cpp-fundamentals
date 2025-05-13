#include <asio.hpp>
#include <asio/io_context.hpp>
#include <iostream>

int main(){
    asio::io_context io;
    asio::ip::tcp::resolver resolver(io);
    auto endpoints = resolver.resolve("example.com", "80");
    for (auto& ep : endpoints)
        std::cout<<ep.endpoint()<<"\n";
}
