/******************************************************************************/
#include <bits/stdc++.h>
using namespace std;


int MST(int nodes, vector<vector<pair<int,int>>> adj){
  
  
   // Min-heap: (weight, node)
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;
  vector<int> visited(nodes,0);
  
  pq.push({0,0});
  int sum=0;
  
  while(!pq.empty()){
    auto it = pq.top();
    pq.pop();
    int node = it.second;
    int wt = it.first;
    if(visited[node]) continue;
    
    
      visited[node]=1;
      sum+=wt;
   for(auto it : adj[node]){
     int adjnode = it.first;
     int edW = it.second;
     if(!visited[adjnode]){
       pq.push({edW,adjnode});
     }
   }
    
  } 
  return sum;
}


int main() 
{
  //create graph with adj >list and weigths ;
    int n, m;
    cin >> n >> m;

    // adjacency list (node -> (neighbor, weight))
    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout<<"enter pair "<<i+1<<" ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }
  
 int minsum = MST(n,adj);
  cout<<"minsum " <<minsum;
} 