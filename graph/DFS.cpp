#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    visited[s] = true;
    cout << "Visited: " << s << " " << endl;
    for (int i : adj[s])
    {
        if (visited[i] == false)
        {
            DFSRec(adj, visited, i);
        }
    }
}

void DFS(vector<vector<int>> &adj, int s)
{
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}

void addEdege(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}
void dfs(vector<vector<int>> &adj, int start)
{
    vector<bool> visited(adj.size(), false);
    visited[start] = true;
    stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int current = st.top();
        st.pop();

        if (!visited[current])
        {
            cout << "Visited: " << current << " ";
            visited[current] = true;
        }
        // duyet nguoc
        // for (int neighBor : adj[current])
        // {
        //     if (!visited[neighBor])
        //     {
        //         visited[neighBor] = true;
        //         st.push(neighBor);
        //     }
        // }
        for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it)
        {
            if (!visited[*it])
            {
                st.push(*it);
            }
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int V = 5;
    vector<vector<int>> adj(V);
    vector<vector<int>> edges = {
        {1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto e : edges)
    {
        addEdege(adj, e[0], e[1]);
    }
    int s = 2; // starting vertex for DFS
    cout << "DFS from source: " << s << endl;
    DFS(adj, s);
    return 0;
}