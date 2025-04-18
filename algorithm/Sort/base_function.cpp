#include "sort.h"
template <class T, class T1>
void swap(T& a, T1& b){
	T tmp = a;
	a = b;
	b = tmp;
}
void print(int arr[], int size){
	std::cout<<std::endl<<"___________________"<<std::endl;
	std::cout<<"Da sap xep roi nhe!"<<std::endl;
	for(int i = 0; i < size; i++){
		std::cout<<(arr[i])<<" ";
	}
}


