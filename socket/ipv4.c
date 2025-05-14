#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
int main()
{
/*    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;
    
    sa.sin_addr.s_addr = INADDR_ANY;
    sa6.sin6_addr = in6addr_any;*/
    struct addrinfo* res = NULL;
    getaddrinfo("google.com", "433", 0, &res);
    struct addrinfo* i;
    for(i=res; i!=NULL; i=i->ai_next)
    {
        char strv4[INET_ADDRSTRLEN];
        char strv6[INET6_ADDRSTRLEN];
        struct sockaddr_in *p = (struct sockaddr_in *)i->ai_addr;
        printf("%s\n", inet_ntop(AF_INET, &p->sin_addr, strv4, sizeof(strv4)));
        struct sockaddr_in6 *p6 = (struct sockaddr_in6 *)i->ai_addr;
        printf("%s\n", inet_ntop(AF_INET6, &p6->sin6_addr, strv6, sizeof(strv6)));
    }
    return 0;
}
