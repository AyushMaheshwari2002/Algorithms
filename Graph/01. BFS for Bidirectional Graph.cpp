/*  IMPLEMENTATION OF BREADTH FIRST SEARCH (BFS)
    
    Time Complexity : O(V + E), where V is the number of nodes and E is the number of edges.
    Space Complexity : O(V)

    Maximum no. of edges possible = (n * (n -1)) / 2        where n = no. of vertexes
*/


#include <bits/stdc++.h>
using namespace std;

void addEdges(vector<int> adjList[] , int src , int dest)
{
    // for bidirestional graph
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
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


vector<int> bfs(vector<int> adjList[] , int vertex)
{
    vector<bool> visited;
    visited.resize(vertex , false);
    
    vector<int> v;
    
    queue<int> q;
    
    // we have always make starting node manually after that make neighbours of that node
    // means perform BFS on the graph starting from vertex "0"
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int node = q.front();
        v.push_back(node);
        q.pop();
        
        for(auto it : adjList[node])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    return v;
}


int main()
{
    int vertex , edges;
    
    cout << "Enter number of vertexes in Graph : ";
    cin >> vertex;
    
    cout << "Enter number of edges in Graph : ";
    cin >> edges;
    
    // this will store the node and the connected nodes of that node
    vector<int> adjList[vertex];
    
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
    vector<int> adjList[vertex];
    addEdges(adjList , 0 , 1);
    addEdges(adjList , 0 , 2);
    addEdges(adjList , 0 , 3);
    addEdges(adjList , 1 , 2);
    addEdges(adjList , 1 , 3);
    addEdges(adjList , 3 , 2);
    */
    
    // this will show which node is connected to which nodes
    printGraph(adjList , vertex);
    
    cout << endl;
    
    vector<int> ans = bfs(adjList , vertex);
    
    cout << "BFS Traversal of the Graph is : " << endl;
    for(auto it : ans)
    {
        cout << it << "    ";
    }
    
    return 0;
}


