#include "BigInt.h"

int main(){
  std::string a, b;
  std::cout<<"Nhap so dau tien = ";
  std::cin>>a;
  std::cout<<"Nhap so thu hai = ";
  std::cin>>b;
  std::cout<<"Ket qua: ";
  BigInt A(a);
  BigInt B(b);
  (A+B).show();
    //BigInt A("100002");
    //BigInt B("999999");
//    A.show();
    std::cout<<std::endl;
 //   B.show();
    //std::cout<<std::endl;
    //(A+B).show();
    //    BigInt C = A + B;
  //  C.show();
    //std::cout<<std::endl;
    //BigInt F("123125249081590184190248120938120398096859243021948019490128");
    //BigInt K("936025481043845968209380124089046395093485394530948078038542");
    //std::cout<<std::endl;
    //(F+K).show();
    //std::cout<<std::endl;
    return 0;
}
