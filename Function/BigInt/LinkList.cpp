#include "LinkList.h"
Node::Node(){
    this->val=0;
    this->next = this->prev = nullptr;

}

Node::Node(int x, Node* next, Node* prev){
    this->val = x;
    this->next = next;
    this->prev = prev;
}
DoubleLinkList::DoubleLinkList(){
    this->head = this->tail = nullptr;
}
DoubleLinkList::~DoubleLinkList(){
   Node* tmp = this->head;
   while(tmp){
        Node* next = tmp->next;
        delete tmp;
        tmp = next;
    }
    this->head = this->tail = nullptr;
}
void DoubleLinkList::addLastNode(int &val){
    //std::cout<<"VAL: "<<val<<std::endl;
    if(!this->head){
        this->head = this->tail = new Node(val);
    }
    else{
        this->tail->next = new Node(val, nullptr, tail);
        this->tail = this->tail->next;
    }
}
void DoubleLinkList::show(){
    if(this->head != nullptr){
        Node* tmp = this->head;
        while(tmp){
            std::cout<<tmp->val;
            tmp = tmp->next; 
        }
    }
}
Node* DoubleLinkList::getHead() const{
    return this->head;
}
Node* DoubleLinkList::getTail() const{
    return this->tail;
}
DoubleLinkList DoubleLinkList::operator+(const DoubleLinkList &other){
    int redudant = 0;
    Node* tailThis = this->getHead(); // correct is getTail()->prev
    Node* tailOther = other.getHead();
    DoubleLinkList result;
    
    while(tailThis != nullptr){
        //std::cout<<tailThis->val<<" + "<<tailOther->val<<std::endl;
        int sum = tailThis->val + tailOther->val + redudant;
        std::cout<<"SUM = "<< sum<<std::endl;
        redudant = sum / 10;
        int t = (sum>=10? (sum-10) : sum);
        result.addLastNode(t);
        tailThis = tailThis->next;
        tailOther = tailOther->next;
    }
    if(redudant != 0){
        result.addLastNode(redudant);
    }
    return result;
}

std::string DoubleLinkList::convert(){
    Node* tmp  = this->getTail();
    std::string result ="";
    while(tmp){
        result.insert(0,1,char(tmp->val+'0'));
        tmp = tmp->prev;
    }
    return result;
}
