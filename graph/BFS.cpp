#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void bfs(vector<vector<int>> &adj, int start)
{
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    cout << "Start at " << start << endl;
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
        cout << endl;
    }
    cout << endl;
}

/*
    with each E is have 0 - 1 weight
*/

void bfs01(int n, int source, vector<vector<int>> &adj)
{
    vector<int> dist(n, INT_MAX); // first distance is unlimits;
    deque<int> dq;
    dist[source] = 0;
    dq.push_front(source);
    while (!dq.empty())
    {
        int curr = dq.front();
        cout << "Source: " << curr << endl;
        dq.pop_front();
        for (int v = 0; v < n; ++v)
        {
            int weight = adj[curr][v]; // weight u -> v
            if (weight != -1 && dist[curr] + weight < dist[v])
            {
                dist[v] = dist[curr] + weight;
                if (weight == 0)
                {
                    dq.push_front(v);
                }
                else
                {
                    dq.push_back(v);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << "Distance to vertex " << i << ":";
        if (dist[i] == INT_MAX)
        {
            cout << "Unreachable" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
}

int main()
{
    // Định nghĩa đồ thị dưới dạng danh sách kề (adjacency list)
    // vector<vector<int>> graph = {
    //     {},        // Đỉnh 0 (không sử dụng)
    //     {2, 3},    // Đỉnh 1 kề với 2, 3
    //     {1, 4, 5}, // Đỉnh 2 kề với 1, 4, 5
    //     {1},       // Đỉnh 3 kề với 1
    //     {2},       // Đỉnh 4 kề với 2
    //     {2}        // Đỉnh 5 kề với 2
    // };

    // int start = 3; // Đỉnh bắt đầu
    // bfs(graph,start);

    int n = 6;                                         // Số đỉnh
    vector<vector<int>> matrix(n, vector<int>(n, -1)); // Ma trận trọng số (-1 nghĩa là không có cạnh)

    // Khởi tạo ma trận trọng số
    matrix[0][1] = 0;
    matrix[0][2] = 1;
    matrix[1][2] = 0;
    matrix[1][3] = 1;
    matrix[2][3] = 0;
    matrix[3][4] = 1;
    matrix[4][5] = 0;

    int source = 4; // Đỉnh nguồn
    bfs01(n, source, matrix);

    return 0;
    return 0;
}