//DFS using recursion
#include <bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>& visistedArray,vector<int>& dfs, vector<vector<int>>& adjList){
 visistedArray[node]=1;
    dfs.push_back(node);
  for(auto it:adjList[node]){
    if(!visistedArray[it]){
    DFS(it,visistedArray,dfs,adjList);
      } 
  }
}

int main() 
{
  //make graph and adj list 
  int nodes = 8;
  int edges = 8;
  vector<vector<int>> adjList(nodes+1);
  for(int i=1;i<=edges;i++){
    int u,v;
    cout<<"enter pair "<<i<<":";
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  vector<int> visited(nodes+1,0);
  vector<int> dfs;
 
    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    DFS(startNode, visited, dfs, adjList);
  for(auto i:dfs){
    cout<<i<<" ";
  }
}