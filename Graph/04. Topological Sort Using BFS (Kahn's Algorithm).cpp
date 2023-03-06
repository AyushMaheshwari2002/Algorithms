/*  Topological Sorting means linear ordering of vertices such that there is an edge u —-> v, u appears before v in the ordering.
    Topological Sorting is applicable only for DAG(Directed Acyclic Graph).

    Time Complexity: O(N + E)           where N = Number of node, E = Number of Edges
    Space Complexity: O(N) + O(N)       Indegree Array and Queue data structure. Both will be using O(N).
*/




#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<int> adjList[])
{
    queue<int> q;
    vector<int> indegree(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        for(auto it : adjList[i])
            indegree[it]++;
    }
    
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto i : adjList[node])
        {
            indegree[i]--;
            if(indegree[i] == 0)
                q.push(i);
        }
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
        Enter Number of Nodes and Edges : 6 6
        Enter Source Node and the nodes that are connected to that node : 
        5 2
        5 0
        4 0
        4 1
        3 1
        2 3
        Topological Sort is : 
        4 5 2 0 3 1 
*/



