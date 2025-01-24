/*
    Run some test case of leetCode.cpp;
*/

#include "leetCode.h"

int main()
{
    FindEventualSafeStates a;
    vector<vector<int>> table = {{1,2},{2,3},{5},{0},{5},{},{}}; 
    a.eventualSafeNodes(table);
}

