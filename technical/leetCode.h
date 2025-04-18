#ifndef LEET_CODE_H_
#define LEET_CODE_H_

//library
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <limits>
#include <climits>
#include <bitset>
using namespace std;
class FindEventualSafeStates{
public:
	void show(vector<vector<int>>& table)const;
	vector<int> eventualSafeNodes(const vector<vector<int>>& graph);
};

class CanConstruct{

/*
    task is: check if string s has exacly k palindrome
*/
/*
    The idea we will talk about is each Palindrome has <= 1 character odd
    Using bitset<128>, we store and manipulate bits to track character frequencies.
        we use flip to toggle bit at the index corresponding to the character 'c' which changes the state of the bit.
        As a result -> we have a bit set to 1 represents a character with and odd frequency/

        Finnaly, we check if the total number of bits set to 1 <= k. If true, string s can be constructed in to k palindrome

*/ 
public:
	bool canConstruct(string s, int k);
};
class CountPrefixAndSuffix{
public:
	bool isPrefix(const string& str1, const string& str2);
	bool isSuffix(const string& str1, const string& str2);
	bool isPrefixAndSuffix(string& str1, string& str2);
	int countPrefixSuffixPairs(vector<string>& words);
};

struct ListNode{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class MergeTwoListAndSort
{
public:
	ListNode *merge(ListNode *l1, ListNode *l2);
	int getMinVal(ListNode *all);
        void delNode(ListNode *&all, int val);
	ListNode *mergeAndSort(ListNode *l1, ListNode *l2);
        void show(ListNode *al);
};

class MergeTwoList{
public:
	void merge(ListNode* list1,ListNode* list2);
	ListNode *getPos(ListNode* list1, int val);
	bool isRightPos(ListNode* list1, ListNode* list2, ListNode* dmp);
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
	void deAllocate(ListNode* list1);
	void recursiveDeAllocate(ListNode* list1);
};


// give a String then count length of the last words.
class LenghOfLastWord
{
public:
    // base on space to get the last tring in s
	string getLastString(string s);
	string trim(const std::string &s);
	int lengthOfLastWord(string s);
};

// give a length to make a triangle pascal
class TrianglePascal
{
public:
    // caculate combination;
	int combination(int n, int k);
	vector<vector<int>> generate(int numRows);
}; 
/*
    give array number then + 1;
    ex: [1,2,3];
    output: [1,2,4]; because : 123 + 1 = 124;
    ex: [9];
    output: [1,0]: because : 9+1 = 10;
*/
class PlusOne
{
public:
	vector<int> plusOne(vector<int> &digits);
};

// given an array nums and target then return 4 nums has total sum == target |
// remember it can be larger than 1 (4 elements);
class ForSum4
{
public:
	vector<vector<int>> ForSum4New(vector<int> &nums, int target);
}; 
class SingleNumber
{
// given a array nums, and return the numbs has appear one times
public:
	int singleNumber(vector<int>& nums);
	int singleNumber(vector<int>& nums, bool f);
}; 

// Given a string s, return the longest
class StringLongestPalindrome
{
public:
	string longestPalindrome(string s);
};

// find 3 nums and total sum them == 0
class ThreeSum
{
public:
	vector<vector<int>> threeSum(vector<int> nums);  
};

class LinkedList
{
public:
	ListNode* deleteDuplicates(ListNode* head);
	bool hasCycle(ListNode* head);
	bool hasCycleV2(ListNode* head);
	ListNode* removeElements(ListNode* head, int val);

};
// easy for extend 2 array
class ExtendArray
{
private:
    int n;
    vector<int> A;
    vector<int> B;
public:
	void setN();
	vector<int> &getA();
	vector<int> &getB();
	int getN();
	void inputArr(vector<int>& tmp);
	void mergeArr();
	void view() const;
};


/*
    Marisa has n mushroom, mushroom i heavy A[i].
    Today she wants to make a potion. She can use any number of mushrooms for a potion
    but the two mushrooms have too much difference in weight. k cannot be used in the same bottle.
    How many mushrooms can be used to make a potion? (Marisa wants her potion to be as strong as possible).
*/
class MixPoison
{
private:
    int n, k;
    vector<int> lineMatrix;
public:
	MixPoison(int n, int k) : n(n), k(k) {}
	MixPoison() : n(0), k(0) {}
	MixPoison(int n): n(n), k(0) {}
	void pushMatrix();
	void silidingWindow();
}; 

// Haunt Traveling
/*
    Haunt is traveling, he has Time, Money and some place to go;
    please, help Haunt to make a plan to get a highest score about
    happy?
*/
class Travel
{
    int t, b, n;
    vector<vector<int>> matrix;
    vector<int> T; // time
    vector<int> C; // fee need to pay
    vector<int> W; // Weight happy
public:
	void input();
	int process();
};


// LIS: Longest Int (Numbers) Subsequence
class LIS
{
private:
    vector<int> inputLine;
    vector<int> L;
    int n;

public:
	LIS(int n) : n(n) {}
	LIS() : n(0) {}
	void input();
	void process();
};
#endif
