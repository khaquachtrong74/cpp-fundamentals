#include<iostream>
#include<string>
using namespace std;
struct A{
	int x, y;
	A(): x(0), y(0) {}
};
struct B{
	A a;
	A b;
};
string printDiaChi(string a){
	return "Dia chi " + a + " ";
}
void line(){
	cout<<"---------------------"<<endl;
}
int main(){
	B c[2]; 
	cout<<printDiaChi("c")<<&c[0]<<endl;
	cout<<printDiaChi("ca")<<&c[0].a<<endl;
	cout<<printDiaChi("cb")<<&c[0].b<<endl;
	cout<<printDiaChi("1")<<&c[0].a.x<<endl;
	cout<<printDiaChi("2")<<&c[0].a.y<<endl;
	cout<<printDiaChi("3")<<&c[0].b.x<<endl;
	cout<<printDiaChi("4")<<&c[0].b.y<<endl;
	cout<<printDiaChi("d")<<&c[1]<<endl;
	cout<<printDiaChi("1")<<&c[1].a.x<<endl;
	cout<<printDiaChi("2")<<&c[1].a.y<<endl;
	cout<<printDiaChi("3")<<&c[1].b.x<<endl;
	cout<<printDiaChi("4")<<&c[1].b.y<<endl;
	line();
	cout<<printDiaChi("c + 1")<<&c[0] + 1 <<endl;
	cout<<printDiaChi("c[0].a + 1")<<&c[0].a+1<<endl;
	cout<<printDiaChi("c[0].b + 1")<<&c[0].b + 1<<endl;
	cout<<printDiaChi("c[1].a + 1")<<&c[1].a + 1<<endl;
}
