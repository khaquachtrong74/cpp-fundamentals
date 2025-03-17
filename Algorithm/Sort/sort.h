#ifndef _SORT_H
#define _SORT_H
#include<iostream>
#include<vector>
#include<array>
template<class T, class T1>
void swap(T& a, T1& b);
void print(int arr[], int size);
template<typename T>
class Sort{
public:
	// flg mean increase(true) or decrease(false)
	void insertion_sort(T arr[], int size, bool flg);
	void slection_sort(T arr[], int size, bool flg);
	void bubble_sort(T arr[], int size, bool flg);
	void interchange_sort(T arr[], int size, bool flg);	
};
#endif
