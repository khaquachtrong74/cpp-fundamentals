// Vì không muốn include thư viện
// nên mình sẽ dùng systemcall để xem
// số bit của từng kiểu dữ liệu


// In extern "C" int write(int, const char*, unsigned int);
// the extern "C" keyword tells the C++ compiler not to apply 
// C++ name mangling to the function.
extern "C" int write(int, const char*, unsigned int);
void putChar(char c){
	write(1, &c, 1);
}
void printBits(unsigned long long x, int size){
	char buffer[65]; // maximum 64bits and nullptr;
	buffer[size] = '\n';
	buffer[size+1] = '\0'; //null
	for(int i = size-1; i >= 0; i--){
		buffer[i] = (x&1) ? '1' : '0';
		x>>=1;
	}
	write(1, buffer, size+1);
};
void delStorage(char* data){
	delete data;
}
int main(){
	char c = 'A';	// 8 bits
	int i = 5;	// 32 bits
	long l = 123;	// 64 bits
	float f = 3.14;	// 32 bits
	double d = 3.14;// 64 bits
	char s = 'c';
	printBits(c, 8);
	printBits(i, 32);
	printBits(l, 64);
	printBits(*reinterpret_cast<unsigned int*>(&f), 32);
	printBits(*reinterpret_cast<unsigned long long*>(&d), 64);
}
