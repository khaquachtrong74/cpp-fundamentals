#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, int start)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    cout<<"Start at "<<start<<endl;
    q.push(start);
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << "Visited: " << current << " ";
        for (int neighBor : adj[current])
        {
            if (!visited[neighBor])
            {
                visited[neighBor] = true;
                q.push(neighBor);
            }
        }
        cout<<endl;
    }
    cout << endl;
}

int main()
{
    // Định nghĩa đồ thị dưới dạng danh sách kề (adjacency list)
    vector<vector<int>> graph = {
        {},        // Đỉnh 0 (không sử dụng)
        {2, 3},    // Đỉnh 1 kề với 2, 3
        {1, 4, 5}, // Đỉnh 2 kề với 1, 4, 5
        {1},       // Đỉnh 3 kề với 1
        {2},       // Đỉnh 4 kề với 2
        {2}        // Đỉnh 5 kề với 2
    };

    int start = 3; // Đỉnh bắt đầu
    bfs(graph,start);

    return 0;
}