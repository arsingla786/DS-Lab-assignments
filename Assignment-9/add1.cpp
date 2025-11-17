#include <bits/stdc++.h>

using namespace std;

void BFS(int start,vector<vector<int>>& adjList,vector<int>& visitedArr){
  vector<int> bfs;
  
  visitedArr[start]=1;
  queue<int> q ;
  q.push(start);
  while(!q.empty()){
    int node = q.front();
    bfs.push_back(node);
    q.pop();
  
  for(auto it:adjList[node]){
    if(!visitedArr[it]){
        visitedArr[it]=1;
      q.push(it);
    }
  }
}  

}

int main() 
{
    int nodes = 5;
    int edges = 3;
    
    vector<vector<int>> adjList(nodes+1);
    for(int i=1;i<=edges;i++){
        int u,v;
        cout<<"enter pair "<<i<<":";
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    
   vector<int> visitedArr(nodes+1,0);
    int components = 0; 
    for(int i=1;i<=nodes;i++){
        if(!visitedArr[i]){
            components++;
            BFS(i,adjList,visitedArr);
        }
    }
    
    cout<<"componenets = "<<components<<endl;
}






