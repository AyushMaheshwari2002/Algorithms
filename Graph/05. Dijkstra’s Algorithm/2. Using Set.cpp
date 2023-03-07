/*    Dijkstra's Algorithm - Single Source Shortest Path Algorithm
      The only differnece of using SET is "it reduces some number of iterations by erasing the nodes that was visited previously at a greater cost". 

      Time Complexity: O(E log(V))        Where E = Number of edges and V = Number of Vertex.
      Space Complexity: O(|V| + |E|)      Where E = Number of edges and V = Number of Vertex.
*/



#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(int n, vector<vector<int>> adjList[], int src)
{
    set<pair<int,int>> st;
    vector<int> dist(n, 1e9);
    
    dist[src] = 0;
    st.insert({0,src});
    
    while(!st.empty())
    {
        auto it = *(st.begin());        // iterator points to the stating pair of {dist,node}
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        
        for(auto i : adjList[node])
        {
            int nextNode = i[0];
            int nextDis = i[1];
            
            if(dis + nextDis < dist[nextNode])
            {
                // erase from set if node was visited previously at a greater cost.
                if(dist[nextNode] != 1e9) 
                    st.erase({dist[nextNode], nextNode});
                
                // If current distance is smaller, push it into set
                dist[nextNode] = dis + nextDis;
                st.insert({dis + nextDis, nextNode});
            }
        }
    }
    return dist;
}

int main()
{
    int vertex, edge;
    cout << "Enter number of vertices and edges : ";
    cin >> vertex >> edge;
    
    vector<vector<int>> adjList[vertex];
    
    cout << "\nEnter Source Node, node that are connected to that node & weight : " << endl;
    for(int i = 0; i < edge; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adjList[u].push_back({v,wt});
        // adjList[v].push_back({u,wt});       
    }
    
    int src;
    cout << "Enter Source Vertex : ";
    cin >> src;
    
    vector<int> ans = dijkstraAlgo(vertex, adjList, src);
    
    cout << "\nThe distance from Source to all the vertices are : " << endl;   
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}



/* OUTPUT :
          Enter number of vertices and edges : 9 14
          Enter Source Node, node that are connected to that node & weight : 
          0 1 4
          1 2 8
          2 3 7
          3 4 9
          0 7 8
          7 6 1
          6 5 2
          5 4 10
          1 7 11
          7 8 7
          2 8 2
          8 6 6
          2 5 4
          3 5 14
          
          Enter Source Vertex : 0
          
          The distance from Source to all the vertices are : 
          0->0  0->1  0->2  0->3  0->4  0->5  0->6  0->7  0->8
          0     4     12    19    21    11    9     8     14 
*/





