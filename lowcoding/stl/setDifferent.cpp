#include<iostream>
#include<set>#include<vector>
using namespace std;
int main(){
    size_t size;
    set<int> result;
    cin>>size;
    for(int i = 0; i < size; i++){
        int temp;
        cin>>temp;
        result.insert(temp);
    }
    cout<<"So luong phan tu khac nhau:= "<<result.size()<<'\n';
    return 0;
}
