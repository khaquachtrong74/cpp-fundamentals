#ifndef _SEARCH_H
#define _SEARCH_H
/*Độ phức tạp
 * Thời gian: O(n)
 * KHông gian: O(1)
 * */
int linearSearch(int arr[], int target, int n);
/*Độ phức tạp
 * Thời gian: O(log2[n])
 * Không gian: O(1)(hằng số) thay vì O(log N) với bản đệ quy
 * */
int binarySearch(int arr[], int target, int n);
// Tìm kiếm tam phân 
// Dùng để tìm giá trị lớn nhất, nhỏ nhất của unimodal function

int terrnaryI(int arr[], int target, int n);



#endif
