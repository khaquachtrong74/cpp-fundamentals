#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string>myQueue;
    size_t size;
    cin>>size;
    myQueue.push("1");
    while(size--){
        string tmp = myQueue.front();
        cout<<tmp<<" ";
        myQueue.pop();
        myQueue.push(tmp + "0");
        myQueue.push(tmp + "1");
        
    }
    return 0;

}
