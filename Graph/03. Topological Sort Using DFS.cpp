/*  Topological Sorting means linear ordering of vertices such that there is an edge u —-> v, u appears before v in the ordering.
    Topological Sorting is applicable only for DAG(Directed Acyclic Graph).

    Time Complexity: O(N + E)           where N = Number of node, E = Number of Edges
    Space Complexity: O(N) + O(N)       Visited Array and Stack data structure. Both will be using O(N).
    Auxiliary Space Complexity: O(N)
*/




#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &s, vector<int> adjList[])
{
    visited[node] = true;
    for(auto it : adjList[node])
    {
        if(!visited[it])
            dfs(it, visited, s, adjList);
    }
    s.push(node);
}

vector<int> topoSort(int n, vector<int> adjList[])
{
    stack<int> s;
    vector<bool> visited(n, false);
    
    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
            dfs(i, visited, s, adjList);
    }
    vector<int> topo;
    while(!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }

    return topo;
}

int main()
{
    int n, m;
    cout << "Enter Number of Nodes and Edges : ";
    cin >> n >> m;

    vector<int> adjList[n + 1];
    
    cout << "\nEnter Source Node and the nodes that are connected to that node : " << endl;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> ans = topoSort(n, adjList);

    cout << "\nTopological Sort is : " << endl;
    for(int i : ans)
        cout << i << " ";

    return 0;
}



/* OUTPUT :
        Enter Number of Nodes and Edges : 6 8
        Enter Source Node and the nodes that are connected to that node : 
        1 2
        1 3
        2 5
        2 4
        3 4
        3 6
        4 5
        4 6
        Topological Sort is : 
        1 3 2 4 6 5
*/



