#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include<iostream>

struct Node{
	int val;
	Node* next;
	Node* prev;
	Node();
	Node(int x, Node* next = nullptr, Node* prev = nullptr);
};
class DoubleLinkList{
private:
	Node* head = new Node();
	Node* tail = new Node();
public:
	DoubleLinkList();
	~DoubleLinkList();
	void addLastNode(int &val);	
	void show();
	Node* getHead() const;
	Node* getTail() const;
	// Xử lý khi cộng 2 bigInt có độ dài bằng nhau
	DoubleLinkList operator+(const DoubleLinkList& other);
	std::string convert();
};
#endif

