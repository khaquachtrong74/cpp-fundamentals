#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    size_t size;
    cin>>size;
    map<int, int>myMap;
    vector<int>arr;
    for(int i = 0; i < size; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    for(int x : arr){
        myMap[x]++;
    }
    for(auto const& [key, val] : myMap){
        std::cout << key << " xuat hien " << val << " lan\n";
    }

    
    return 0;
}
