// Abstract Data Type - ADT
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX 100
/*
    Abstract Data Type
    List -> 8, 3, 4, 4, 6, 10, 12
            0  1  2  3  4  5   6

    Data: 1- Space for storing elements
          2- Capacity
          3- Size

    We can use Array or linkedlist

    Some Operations:
                    + add(x) // add to the end of list
                    + add(index, x) insert element at index
                    + remove(index)
                    + set(index, x) replace element at index
                    + get(index)
                    + search(key) / contains(key)
                    + sort()
                    + split()
                    + merge()


    Define the data, and operations on data together
    Let it be used as data type.

    build data struct

*/

/*
    PURPOSE: BUILD LIST, SET, ARRAY, LINKEDLIST, QUEUE, DEQUEUE, STACK, HASHMAP
    DATE: 17/11/2024
*/

// LIST - Array
class List
{
private:
    int arrayStore[MAX];
    int capacity;
    int size;

public:
    List() : capacity(100), size(0) {}
    List(int cap) : capacity(cap), size(0) {}
    ~List()
    {
        for (int i = 0; i < capacity; i++)
        {
            arrayStore[i] = 0;
        }
    }
    List *append(int el);
    List *append(int index, int el);
    void *remove(int index);
    void *set(int index, int el);
    int *get(int index);
    // linear Search
    int *search(int key);
    // low -> high | it's work but not effective
    void sort();
    void split();
    void merge();
};
List *List::append(int el)
{
    if (size < capacity)
    {
        arrayStore[size++] = el;
        return this;
    }
    else
    {
        return nullptr;
    }
}
List *List::append(int index, int el)
{
    if (size < capacity - 1 && index < size && index >= 0)
    {
        for (int i = size; i > index; i--)
        {
            arrayStore[i] = arrayStore[i - 1];
        }
        arrayStore[index] = el;
        size++;
        return this;
    }
    else
    {
        return nullptr;
    }
}
void *List::remove(int index)
{
    if (index == size - 1)
    {
        arrayStore[index] = 0;
        size--;
        return this;
    }
    if (index < size && index >= 0)
    {
        for (int i = index; i < size - 1; i++)
        {
            arrayStore[i] = arrayStore[i + 1];
        }
        return this;
    }
    return nullptr;
}
void *List::set(int index, int el)
{
    if (index >= 0 && index < size)
    {
        arrayStore[index] = el;
        return this;
    }
    else
    {
        return nullptr;
    }
}
int *List::get(int index)
{
    if (index >= 0 && index < size)
    {
        return &arrayStore[index];
    }
    else
    {
        return nullptr;
    }
}
int *List::search(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arrayStore[i] == key)
            return &arrayStore[i];
    }
    return nullptr;
}
void List::sort()
{
    if (size <= 0)
        return;
    // allocation heap memory
    int *newArrayStore = new int[size];
    int newSize = 0;
    int root, pos = 0;
    // case list have each elements different
    while (pos < size)
    {
        root = arrayStore[pos];
        if (root == -1)
        {
            pos++;
            continue;
        }
        for (int i = pos + 1; i < size; i++)
        {

            if (arrayStore[i] != -1 && arrayStore[i] <= root)
            {
                newArrayStore[newSize++] = arrayStore[i];
                arrayStore[i] = -1;
            }
        }
        newArrayStore[newSize++] = root;
        pos++;
    }
    for (int j = 0; j < size; j++)
    {
        arrayStore[j] = newArrayStore[j];
    }
    // release memory
    delete[] newArrayStore;
    newArrayStore = nullptr;
}

// Hash - MAP
template <typename T>
class Optional
{
private:
    bool hasValue;
    T value;

public:
    Optional() : hasValue(false) {}
    Optional(const T &val) : hasValue(true), value(val) {}
    bool isHashValue() const { return hasValue; }
    T valueOr(const T &defaultValue) const
    {
        return hasValue ? value : defaultValue;
    }
};
template <typename T>
class HashTable
{
private:
    vector<int> table;
    const int MATERIAL = 13;

public:
    HashTable(int material = 13) : MATERIAL(material)
    {
        table.resize(MATERIAL, -1);
    }
    T hashFunction(T val)
    {
        return val % MATERIAL;
    }
    void push(T val)
    {
        int idx = hashFunction(val);
        while (table[idx] != -1)
        {
            idx = (idx + 1) % MATERIAL; // xử lý theo kiểu dò tuyến tính
        }
        table[idx] = val;
    }
    T getIndexOf(T val)
    {
        int idx = hashFunction(val);
        while (table[idx] != val)
        {
            idx = (idx + 1) % MATERIAL;
            if (table[idx] == -1)
                return -1;
        }
        return idx;
    }
    void printTable()
    {
        for (auto x : table)
        {
            cout << x << " " << endl;
        }
    }
};

// make a stack class

template <typename T>
class Stack
{
private:
    T *array;
    int capacity;
    int top;

public:
    Stack(int size = MAX) : top(-1), capacity(size)
    {
        try
        {
            array = new T[capacity];
        }
        catch (const bad_alloc &e)
        {
            throw runtime_error("Failed to allocate memory for stack");
        }
    }
    // copy constructor to implement Rule of Three
    Stack(const Stack &other) : capacity(other.capacity), top(other.top)
    {
        try
        {
            array = new T[capacity];
            for (int i = 0; i <= top; i++)
            {
                array[i] = other.array[i];
            }
        }

        catch (const bad_alloc &e)
        {
            throw runtime_error("Failed to allocate memory in copy constructor");
        }
    }
    Stack &operator=(const Stack &other)
    {
        if (this != &other)
        {
            T *newArray = new T[other.capacity];
            for (int i = 0; i < other.top; i++)
            {
                newArray[i] = other.array[i];
            }
            delete[] array;
            array = newArray;
            capacity = other.capacity;
            top = other.top;
        }
        return *this;
    }
    ~Stack()
    {
        delete[] array;
        array = nullptr;
    }
    bool isFull() const
    {
        return top == capacity - 1;
    }
    bool isEmpty() const
    {
        return top < 0;
    }
    // push(el)
    void push(const T &el)
    {
        if (!isFull())
        {
            array[++top] = el;
            cout << "Push successfully." << el << endl;
        }
        else
        {
            throw overflow_error("Stack overflow: Cannot put elements. ");
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            cout << "Pop successfully: " << array[top--] << endl;
        }
        else
        {
            throw underflow_error("Stack underflow: cannot pop.");
        }
    }
    T getTop() const
    {
        if (!isEmpty())
            return array[top];
        else
            throw out_of_range("Stack is empty: No top elements.");
    }
    void view() const
    {
        if (isEmpty())
            cout << "Stack is empty." << endl;
        else
        {
            cout << "Stack elements: ";
            for (auto x : array)
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void insertSorted(int el)
    {
        if (isEmpty() || this->getTop() < el)
        {
            this.push(el);
            return;
        }
        else
        {
            int temp = this->getTop();
            this->pop();
            insertSorted(el);
            this->push(temp);
        }
    }
    void sort()
    {
        if (this->isEmpty())
        {
            return;
        }
        int temp = this->getTop();
        this->pop();
        sort();
        insertSorted(temp);
    }

    T searchEl(T el){
        Stack tmp(this);
        for(auto x : tmp.array){
            if(x == el) return el;
        }
        return -1;
    }

};

// Make class Queue

template <typename T>
class Queue
{
private:
    T *array;
    int capacity;
    int rear;
    int front;
    int size;

public:
    Queue(int cap = MAX) : capacity(cap), front(0), rear(-1), size(0)
    {
        try
        {
            array = new T[capacity];
        }
        catch (const bad_alloc& e){
            throw runtime_error("Failed to allocate memory for Queue");
        }
    }
    Queue(const Queue& other): capacity(other.capacity), size(other.size), rear(other.rear), front(other.front){
        try{
            array = new T[capacity];
            for(int i = 0; i < size; i++){
                array[i] = other.array;
            }
        }
        catch(const bad_alloc& e){
            throw runtime_error("Failed to allocate memory in copy constructor");
        }
    }
    Queue &operator=(const Queue& other){
        if(this != &other){
            T* newArray = new T[other.capacity];
            for(int i = 0; i < other.size; i++){
                newArray[i] = other.array[i];
            }
            delete [] array;
            array = newArray;
            capacity = other.capacity;
            rear = other.rear;
            front = other.front;
            size = other.size;
        }
    }
    ~Queue()
    {
        delete[] array;
        array = nullptr;
    }
    bool isFull() const
    {
        return size == capacity;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    void enQueue(T el)
    {
        if (isFull())
        {
            throw overflow_error("Queue overflow: Cannot enQueue el. ");
            
        }
        else
        {
            rear = (rear + 1) % capacity; // circle;
            array[rear] = el;
            size++;
            cout << " Enqueed successfully: " << el << endl;
        }
    }
    void deQueue()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue underflow: Cannot dequeue. ");
            return;
        }
        cout << "Dequeued succesfully: " << array[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }
    T getFront() const
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is empty: No front elements.");
        }
        return array[front];
    }
    T getRear() const
    {
        if (isEmpty())
        {
            throw out_of_range("Queue is empty: No Rear elements.");
        }
        return array[rear];
    }

    void view() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty. " << endl;
            return;
        }
        else
        {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++)
            {
                cout << array[(front + i) % capacity] << "->";
            }
            cout << endl;
        }
    }
    // void sort(){
        
    // }
};

// make a Double-Ended Queue

template <typename T>
class Deque
{
private:
    T *array;
    int capacity;
    int rear;
    int rear;
    int size;

public:
    Deque(int cap = MAX) : capacity(cap), rear(0), rear(-1), size(0)
    {
        array = new T[capacity];
    }
    ~Deque()
    {
        delete[] array;
        array = nullptr;
    }
    bool isFull() const
    {
        return size == capacity;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    void pushrear(T el)
    {
        if (isFull())
        {
            cout << "Deque overflow: cannot push rear " << el << endl;
            return;
        }
        else
        {
            rear = (front - 1 + capacity) % capacity; // circle
            array[rear] = el;
            size++;
            cout << "Push successfully: " << el << endl;
        }
    }
    void pushRear(T el)
    {
        if (isFull())
        {
            cout << "Deque overflow: cannot push rear " << el << endl;
            return;
        }
        else
        {
            rear = (rear + 1 + capacity) % capacity; // circle
            array[rear] = el;
            size++;
            cout << "Push successfully: " << el << endl;
        }
    }
    void poprear()
    {
        if (isEmpty())
        {
            cout << "Deque underflow: Cannot remove rear elements. " << endl;
            return;
        }
        else
        {
            cout << "Remove rear elements: " << array[front] << endl;
            rear = (front + 1) % capacity;
            size--;
        }
    }
    void popRear()
    {
        if (isEmpty())
        {
            cout << "Deque underflow: Cannot remove Rear elements. " << endl;
            return;
        }
        else
        {
            cout << "Remove Rear elements: " << array[rear] << endl;
            rear = (rear - 1 + capacity) % capacity;
            size--;
        }
    }
    T getFront() const
    {
        if (isEmpty)
        {
            throw out_of_range("Deque is empty: No front elements");
        }
        else
        {
            return array[front];
        }
    }
    T getRear() const
    {
        if (isEmpty)
        {
            throw out_of_range("Deque is empty: No rear elements");
        }
        else
        {
            return array[rear];
        }
    }
    // view
    void view() const
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }
        else
        {
            cout << "Deque elements.";
            for (int i = 0; i < size; ++i)
            {
                cout << array[(front + i) % capacity] << "->";
            }
            cout << endl;
        }
    }
};
