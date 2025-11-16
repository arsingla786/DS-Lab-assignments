//graph  BFS 

#include<bits/stdc++.h>
using namespace std;
vector<int> BFS(int nodes,vector<vector<int>>& adjList,int first){
  vector<int> bfs;
  int visitedArray[nodes+1]={0};
  visitedArray[first] = 1;
  
  queue<int> q;
  q.push(first);
  
  while(!q.empty()){
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for(auto it : adjList[node]){
      if(!visitedArray[it]){
        visitedArray[it] =1;
        q.push(it);
      }
    }
  }
  return bfs;
}

int main() 
{
  int nodes = 10;
  int edges = 9;
  vector<vector<int>> adjList(nodes+1);
  for(int i=1;i<=edges;i++){
    int u,v;
    cout<<"enter pair "<<i<<" : ";
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  vector<int> result = BFS(nodes,adjList,1);
  for(auto i : result){
    cout<<i<<" ";
  }
  
}