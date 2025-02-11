#include<iostream>
// write some functions use bitwise;
// Bitwise will increase speed
// Shortest syntax

int multi(int x){
	return x <<1; // x * 2
}

int divide(int x){
	return x >>1; // x / 2
}

bool isOdd(int x){
	return x & 1;
}
bool isEven(int x){
	return !isOdd(x);
}
int test(int x){
	return x <<2; // Mọi bit dời sang trái 2 lần
}
// Dời bit sẽ quay lại mỗi 32 bit vì int chỉ có 4 bytes
int shiftBits(int n, int k){
	return n << k;
}
int main(){
	int x = 5, n, k;
	printf("X is %d\n", x);

//	printf("Multiple to 2: %d\nDivide to 2: %d\nis odd: %d",
//	multi(x), divide(x), isOdd(x));
	//	Với input x=5; với mã bit là 0101
	//	Dời bit lần 1: x=10 với mã bit 1010
	//	Dời bit lần 2: x=20 với mã bit 0001 0100 || 16 + 4 = 20
	//	Ta có thể xem số lần dời bit = 2^k
//	printf("Test: %d\n", test(x));
	std::cout<<"Input n : ";
	std::cin>>n;
	std::cout<<"Input k : ";
	std::cin>>k;
	std::cout<<"Output Shift bits:= "<<shiftBits(n, k)<<std::endl;
}
