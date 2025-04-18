#include "sort.h"

using namespace std;
int main(){
	int arr[5] = {5,4,1,2,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	Sort<int> a;
/*	a.slection_sort(arr,size, true);
	print(arr, size);
	a.insertion_sort(arr,size,false);
	print(arr, size);
	a.bubble_sort(arr,size,true);
	print(arr, size);
	a.interchange_sort(arr,size,false);*/
	int temp[size];
	a.merge_sort(arr, temp, 0, size-1);
	print(temp, 5);
}
