#include "BigInt.h"

BigInt::BigInt(){
    this->contain = DoubleLinkList();
}
BigInt::~BigInt(){

}
BigInt::BigInt(std::string s){
    std::reverse(s.begin(), s.end());
//    std::cout<<s;
    for(char c : s){
        // error: addLastNode(t);
        int t = int(c - '0');
        this->contain.addLastNode(t);
    }
}
void BigInt::show(){
    this->contain.show();
}
BigInt BigInt::operator+(const BigInt &other){
    DoubleLinkList res = this->contain + other.contain;
    // Convert res -> std::string;
    // bởi vì việc cộng 2 dll sẽ cho ra 1 kết quả bị đảo ngược
    // cho nên để có kết quả đúng ta reverse một lần nữa
    std::string r = res.convert();
//    std::reverse(r.begin(),r.end());
    BigInt result(r);
    return result;
}
