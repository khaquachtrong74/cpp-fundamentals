#include "../include/client.h"
int main(){
    Client clientOne("Hello Server, Good morning!", 1);
    clientOne.Connect();
    clientOne.SendMessage();
    return 0;
}
