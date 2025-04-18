#include "search.h"
#include "../Sort/sort.h"
#include <iostream>
using namespace std;

int main(){
	Sort<int> a =  Sort<int>();
	int arr[] = {5,1,4,3,6};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<linearSearch(arr, 3, size)<<endl;
	a.interchange_sort(arr, size, true);
	cout<<binarySearch(arr, 3, size)<<endl;
	cout<<terrnaryI(arr, 6, size);
}
