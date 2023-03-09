/*    Floyd Warshall algorithm --> Multi-Source Shortest Path Algorithm
      Also helps to detect negative cycles.
      In this algorithm, we use adjacency matrix. 

      Time Complexity: O(V3)          as we have three nested loops each running for V times, where V = no. of vertices.
      Space Complexity: O(V2)         where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
*/



#include<bits/stdc++.h>
using namespace std;

int floyd_warshall(vector<vector<int>> &matrix) 
{
    int n = matrix.size();
    for(int i = 0; i < n; i++) 
    {
      for(int j = 0; j < n; j++) 
      {
        if(i == j) 
          matrix[i][j] = 0;
      }
    }
        
    // Floyd Warshall Algorithm
    for(int via = 0; via < n; via++) 
    {
      for(int i = 0; i < n; i++) 
      {
        for(int j = 0; j < n; j++) 
        {
          matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        }
      }
    }
		
    // check for negative cycles
    for(int i = 0; i < n; i++)
    {
        if(matrix[i][i] < 0) {  
            cout << "Graph contains negative weight cycle!!!" << endl;
              return -1;
        }
    }

    // just for making output user friendly
    // if the node is NOT REACHABLE then make it from 1e9 to -1
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 1e9) {
          matrix[i][j] = -1;
        }
      }
    }
		
    // print the shortest path for each node 
    for(int i = 0; i < n; i++) 
    {
        cout << "Minimum cost with respect to Node : " << i << endl;
        for(int j = 0; j < n; j++) 
        {
          cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

int main()
{
    int vertex = 4;
    
    vector<vector<int>> matrix(vertex, vector<int>(vertex, 1e9));
    
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;

    /*
    int vertex = 3;
    matrix[0][1] = -2;
    matrix[1][2] = -3;
    matrix[2][0] = 2;
    */

    floyd_warshall(matrix);

    return 0;
}




/* OUTPUT:
---------------------------------------------------------------------------------------------------------------------------------------------
        Input :       matrix[0][1] = 2;
                      matrix[1][0] = 1;
                      matrix[1][2] = 3;
                      matrix[3][0] = 3;
                      matrix[3][1] = 5;
                      matrix[3][2] = 4;
        Output :
                      Minimum cost with respect to Node : 0
                      0-->0   0-->1   0-->2   0-->3
                      0	      2     	5     	-1	
                      Minimum cost with respect to Node : 1
                      1-->0   1-->1   1-->2   1-->3
                      1	      0	      3     	-1	
                      Minimum cost with respect to Node : 2
                      2-->0   2-->1   2-->2   2-->3
                      -1	    -1	    0	      -1	
                      Minimum cost with respect to Node : 3
                      3-->0   3-->1   3-->2   3-->3
                      3	      5	      4	      0
---------------------------------------------------------------------------------------------------------------------------------------------------
       Input :        matrix[0][1] = -2;
                      matrix[1][2] = -3;
                      matrix[2][0] = 2;
        Output :
                      Graph contains negative weight cycle!!!
 -----------------------------------------------------------------------------------------------------------------------------------------------------
 
 
 
 
 
 
