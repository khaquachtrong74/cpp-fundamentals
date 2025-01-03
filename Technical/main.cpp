/*
    Run some test case of leetCode.cpp;
*/

#include "leetCode.cpp"

int main()
{
    MergeTwoListAndSort test;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // cout<<test.mergeTwoLists(list1, list2)->val;  
    ListNode *tt = test.mergeAndSort(list1, list2);
    test.show(tt);
}