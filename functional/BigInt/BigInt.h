#ifndef BIG_INT_H_
#define BIG_INT_H_

#include<iostream>
#include<string>
#include<algorithm> // get reverse string 
#include "LinkList.h"

class BigInt{
private:
	DoubleLinkList contain;
public:
	BigInt();
	~BigInt();
	BigInt(std::string s);
	void show();
	BigInt operator+(const BigInt & other);
};

#endif
