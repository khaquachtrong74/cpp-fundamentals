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
	cout<<endl<<"Bubble sort"<<endl;
	for(int i = 0; i < size -1; i++){
		for(int j = size-1; j > i; j--){
			if(flg^!(arr[j] < arr[j-1]))
				swap(arr[j], arr[j-1]);
		}
	}
}

template<class T>
void Sort<T>::interchange_sort(T *arr, int size, bool flg){
	cout<<endl<<"Interchange Sort"<<endl;
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++)
		{
			if(flg^!(arr[i] > arr[j]))
				swap(arr[i], arr[j]);
		}
	}
}


