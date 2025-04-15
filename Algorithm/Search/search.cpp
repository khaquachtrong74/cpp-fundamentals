#include "search.h"

int linearSearch(int *arr, int target, int n){
	for(int i = 0; i < n; i++){
		if(arr[i] == target)
			return i;
	}
	return -1;
}

int binarySearch(int *arr, int target, int n){
	int left = 0;
	int right = n-1;
	while(left <= right){
		int mid = (left + right)/2;
		if(arr[mid] == target)
			return mid;
		if(target > arr[mid])
			left = mid+1;
		else  
			right = mid-1;	
	}
	return -1;
}
int terrnaryI(int *arr, int target, int n){
	int l = 0;
	int r = n-1;
	while(r-l >= 0){
		int partition = (r-l)/3;
		int mid1 = l + partition;
		int mid2 = r - partition;
		if(target == arr[mid1])
			return mid1;
		else if(target == arr[mid2])
			return mid2;
		else if(target < arr[mid1])
			r = mid1 - 1;
		else if(target > arr[mid2])
			l = mid2 + 1;
		else{
			l = mid1 + 1;
			r = mid2 - 1;
		}
	}
	return -1;
}
