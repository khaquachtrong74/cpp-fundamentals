#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
int main(){
    struct addrinfo hints = {0};
    hints.ai_flags = 0;
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    struct addrinfo *res = NULL;
    if(getaddrinfo("youtube.com", "433", &hints, &res) == 0){
        printf("Something\n");
        printf("sa_data: %s\n",res->ai_addr->sa_data);
        printf("protocol: %d\n", res->ai_protocol);
        printf("canonname: %s\n", res->ai_canonname);
    }
}
