/*  IMPLEMENTATION OF DEPTH FIRST SEARCH (DFS)
    
      Time Complexity  : O(V + E), where V is the number of nodes and E is the number of edges.
      Space Complexity : O(V)
*/



#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adjList[] , int src , int dest)
{
    // for bidirestional graph
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}


void dfs(vector<int> adjList[] , int node , vector<int> &visited , vector<int> &v)
{
    v.push_back(node);
    visited[node] = 1;
    
    for(auto it : adjList[node])
    {
        if(!visited[it])
        {
            dfs(adjList , it , visited , v);
        }
    }
}


vector<int> dfsTraversal(vector<int> adjList[] , int vertex)
{
    vector<int> visited(vertex , 0);
    vector<int> v;
    
    queue<int> q;
    
    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            dfs(adjList , i , visited , v);
        }
    }
    
    return v;
}


void printGraph(vector<int> adjList[] , int vertex)
{
    for(int i = 0; i < vertex; i++)
    {
        cout << "The node is : " << i << endl;
        cout << "The neighbours/connected nodes are : ";
        
        for(auto it : adjList[i])
        {
            cout << it << "    ";
        }
        cout << endl;
    }
}


int main()
{
    int vertex , edges;
    
    cout << "Enter number of vertexes in Graph : ";
    cin >> vertex;
    
    cout << "Enter number of edges in Graph : ";
    cin >> edges;
    
    // this will store the node and the connected nodes of that node
    vector<int> adjList[6];
    
    int src , dest;             // source and destination
    
    cout << "\nEnter Source Node and the nodes that are connected to that node : " << endl;
    for(int i = 0; i < edges; i++)
    {
        cin >> src;
        cin >> dest;
        
        addEdges(adjList , src , dest);
    }
    cout << endl;
    
    /*
    int vertex = 6;
    vector<int> adjList[vertex];
    addEdges(adjList , 1 , 2);
    addEdges(adjList , 1 , 3);
    addEdges(adjList , 1 , 4);
    addEdges(adjList , 1 , 5);
    addEdges(adjList , 2 , 4);
    addEdges(adjList , 2 , 1);
    addEdges(adjList , 3 , 1);
    addEdges(adjList , 4 , 1);
    addEdges(adjList , 4 , 2);
    addEdges(adjList , 5 , 1);
    */
    
    // this will show which node is connected to which nodes
    printGraph(adjList , vertex);
    
    cout << endl;
    
    vector<int> ans = dfsTraversal(adjList , vertex);
    
    cout << "DFS Traversal of the Graph is : " << endl;
    for(auto it : ans)
    {
        cout << it << "    ";
    }
    
    return 0;
}




