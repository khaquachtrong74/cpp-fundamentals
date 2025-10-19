#include<iostream>
#include<vector>
#include<climits>
//#define for(size) for(int i = 0; i < size; i++)
using namespace std;
void view(const vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}
void findMinMax(vector<int>&arr, size_t size){
    cout<<"Input\n";
    for(int i = 0; i < size; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"find min\n";
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < size; ++i){
        if(min > arr[i])
            min = arr[i];
        if(max < arr[i])
            max = arr[i];
    }
    cout<<"Min nef: "<<min<<'\n';
    cout<<"Max ne: "<<max<<'\n';
}

vector<int> PrefixSum(const vector<int> arr){
    vector<int>result(arr);
    for(int i = 0; i < result.size(); i++){
        result[i] += (i==0?0:result[i-1]);
    }
    return result;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    size_t query = 4;
    vector<int>prefixSum = PrefixSum(arr);
    view(prefixSum);    
    while(query--){
        // Chỉ số index i và j trên mảng
        int x, y;
        cin>>x>>y;
        cout<<"tong tu chi so "<<x<<" va "<<y<<" = "<<prefixSum[y] - prefixSum[x]<<'\n';
    }
    return 0;
}
