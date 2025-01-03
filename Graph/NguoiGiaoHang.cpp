// Tìm đường đi ngắn nhất qua n thành phố sao cho
// mỗi thành phố chỉ được đi qua duy nhất một lần

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <stack>
#include <climits>
using namespace std;
int minCost = INT_MAX;
void dfs(int currCity, int count, int cost, int start, vector<vector<int>> &city, vector<bool> visited)
{
    if (count == city.size() && city[currCity][start] > 0)
    {
        minCost = min(minCost, cost + city[currCity][start]);
        return;
    }
    for (int nextCity = 0; nextCity < city.size(); ++nextCity)
    {
        if (!visited[nextCity] && city[currCity][nextCity] > 0)
        {
            visited[nextCity] = true;
            
            dfs(nextCity, count + 1, cost + city[currCity][nextCity], start, city, visited);
            // backtrackinng
            visited[nextCity] = false;
        }
    }
}
int main()
{
    ifstream input("Doc/inMat2.txt", ios::in);
    if (!input.is_open())
    {
        cerr << "Can't Open file! " << endl;
    }
    int numbCity;
    cin >> numbCity;
    vector<vector<int>> city(numbCity, vector<int>(numbCity));
    for (int i = 0; i < numbCity; i++)
    {
        for (int j = 0; j < numbCity; j++)
        {
            input >> city[i][j];
        }
    }
    vector<bool>visited(numbCity, false);
    //  begin, end, value
    // fill(visited, visited + 25, false);

    // currentCity : at pos 0
    // among : 1
    // cost : 0
    // start on matrix : 0 
    // matrix city : size(numbCity * numbCity)
    // array boolean visited : size(numbCity)
    dfs(0, 1, 0, 0, city, visited);
    cout << minCost;
}
