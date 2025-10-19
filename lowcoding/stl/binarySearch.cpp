#include<iostream>
#include<vector>
#define i64 long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<i64> arr;
    i64 target;
    size_t size;
    cin>>size>>target;
    for(int i = 0; i < size; i++){
        int temp;
        cin >>temp;
        arr.push_back(temp);
    }
    int left = 0;
    int right = size -1;
    while(left <= right){
        int mid = (left+right)/2;
        if(arr[mid] == target){
            cout<<"YES\n";
            return 0;
        }
        if(arr[mid] < target){
            left = mid + 1;
        }
        if(arr[mid] > target)
            right = mid - 1;
    }
    cout<<"NO\n";
    return 0;

}
