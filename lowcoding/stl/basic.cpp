#include<iostream>
#include<vector>
#include<algorithm>

void duyetMang(const std::vector<int>a){
    for(int i = 0; i < a.size(); ++i){
        std::cout<<a[i]<<" ";
    }
    std::cout<<'\n';
}
int main(){
    std::vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(3);
    std::cout<<"Phan tu dau tien ne: "<<a[0]<<'\n';
    a[1] = 99;
    std::cout<<"Kich thuoc cua mang a: "<<a.size()<<'\n';
    duyetMang(a);
    std::cout<<"Sort nè\n";
    std::sort(a.begin(), a.end());
    duyetMang(a);
}
