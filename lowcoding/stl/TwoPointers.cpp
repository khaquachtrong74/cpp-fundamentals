#include<iostream>
#include<vector>
#define i64 long long 
using namespace std;

int main(){
    vector<i64> arr;
    i64 target;
    size_t size;
    cin>>size>>target;
    for(int i = 0; i < size; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int left=0;
    int right=size-1;
    while(left < right){
        if(arr[left] + arr[right] == target){
            cout<<"YES\n";
            return 0;
        }
        if(arr[left] + arr[right]> target){
            right--;continue;
        }
        if(arr[left] + arr[right]< target){
            left++;
        }
    }
    cout<<"NO\n";

    return 0;
}
