#include "sort.h"

using namespace std;
template class Sort<int>;
template<class T>
void Sort<T>::insertion_sort(T *arr, int size, bool flg){
	cout<<endl<<"Insertion sort "<<endl;
	for(int i=1; i < size; i++){
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && flg^!(arr[j] > key)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}	
}
template<class T>
void Sort<T>::slection_sort(T *arr, int size, bool flg){
	cout<<endl<<"Selection sort"<<endl;
	int min;
	for(int i = 0; i < size - 1; i++){
		min = i;
		for(int j = i+1; j < size; j++){
			if(flg^!(arr[j] < arr[min]))
				min = j;
		}
		if(min != i)
			swap(arr[min], arr[i]);
	}
}

template<class T>
void Sort<T>::bubble_sort(T *arr, int size, bool flg){
	cout<<"Bubble sort"<<endl;
	for(int i = 0; i < size -1; i++){
		for(int j = size-1; j > i; j--){
			if(flg^!(arr[j] < arr[j-1]))
				swap(arr[j], arr[j-1]);
		}
	}
}

template<class T>
void Sort<T>::interchange_sort(T *arr, int size, bool flg){
	cout<<"Interchange Sort"<<endl;
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++)
		{
			if(flg^!(arr[i] > arr[j]))
				swap(arr[i], arr[j]);
		}
	}
}

// Medium
template<class T>
void Sort<T>::merge_parts(T *arr, T *temp, int l, int m, int r){
	int i = l;
	int j = m+1;
	int k = 0;
	while(i <=m && j <=r){
		int nextVal;
		if(arr[i] < arr[j]) nextVal = arr[i++];
		else nextVal = arr[j++];
		temp[k++] = nextVal;
	}
	while(i <= m){
		temp[k++] = arr[i++];
	}
	while(j <= r){
		temp[k++] = arr[j++];
	}
	for(int i = 0; i < k; i++){
		arr[l+i] = temp[i];
	}
}
template<class T>
void Sort<T>::merge_sort(T *arr, T *temp, int l, int r){
	if(l >= r){
		cout<<"Merge SOrt"<<endl;
		return;
	}
	int mid = (l + r)/2;
	merge_sort(arr, temp, l, mid);
	merge_sort(arr, temp, mid+1, r);
	merge_parts(arr, temp, l, mid, r);
}
