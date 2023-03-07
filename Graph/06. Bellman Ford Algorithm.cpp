/*  Bellman Ford Algorithm --> Single Source Shortest Path Algorithm --> only works on directed graph
    
    Bellman Ford means "Relax all the edges N-1 times sequentially".
    It works fine with negative edges.
    It is able to detect that the graph contains a negative cycle or not.
    
    Time Complexity: O(V*E)    where V = no. of vertices and E = no. of Edges
    Space Complexity: O(V)     for the distance array which stores the minimized distances.

*/



#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int n, vector<vector<int>>& adjList, int src)
{
    vector<int> dist(n,1e9);
    dist[src] = 0;
    
    for(int i = 0; i < n-1; i++)
    {
        for(auto it : adjList)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
              dist[v] = dist[u] + wt;
            }
        }
    }
    
    // It is guaranteed that we can find our answer by doing N-1 iterations
    // But if on Nth iteration, during relaxation the dist[] array gets reduces
    // then we can say the graph contains a CYCLE
    for(auto it : adjList)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
          cout << "\nGraph contains negative weight cycle!!!" << endl;
          return {-1};
		    }
    }
    
    return dist;
}

int main()
{
    int vertex, edge;
    cout << "Enter number of vertices and edges : ";
    cin >> vertex >> edge;
    
    vector<vector<int>> adjList(vertex+1, vector<int>(3));
    
    cout << "\nEnter Source Node, node that are connected to that node & weight : " << endl;
    for(int i = 0; i < edge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjList[i] = {u,v,wt};
    }
    
    int src;
    cout << "Enter Source Vertex : ";
    cin >> src;
    
    vector<int> ans = bellman_ford(vertex, adjList, src);
    
    cout << "\nThe distance from Source to all the vertices are : " << endl;   
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}




/* OUTPUT:
  --------------------------------------------------------------------------------------------------------------------------------------------
          Enter number of vertices and edges : 6 7
          Enter Source Node, node that are connected to that node & weight : 
          3 2 6
          5 3 1
          0 1 5
          1 5 -3
          1 2 -2
          3 4 -2
          2 4 3
          Enter Source Vertex : 0
          
          The distance from Source to all the vertices are : 
          0->0  0->1  0->2  0->3  0->4  0->5
          0     5     3     3     1     2 
  ------------------------------------------------------------------------------------------------------------------------------------------------
          Enter number of vertices and edges : 3 3
          Enter Source Node, node that are connected to that node & weight : 
          0 1 -2
          1 2 -1
          2 0 2
          Enter Source Vertex : 0
          
          Graph contains negative weight cycle!!!
          The distance from Source to all the vertices are : 
          -1 
  --------------------------------------------------------------------------------------------------------------------------------------------------- 
          
          
          
          
          
