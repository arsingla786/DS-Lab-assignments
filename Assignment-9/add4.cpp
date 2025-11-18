//no. of islands

class Solution {
public:
void bfs(int start,vector<int>& visitedArr,vector<vector<int>>& adjList){
    visitedArr[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjList[node]){
            if(!visitedArr[it]){
                visitedArr[it]=1;
                q.push(it);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
  // make adj list 
        vector<vector<int>> adjList(n+1);
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                }
             }
        }
        //now we have adj lis , so find components using bfs or dfs
        vector<int> visitedArr(n+1,0);
        int components = 0;
        for(int i=0;i<n;i++){
            if(!visitedArr[i]){
                components++;
                bfs(i,visitedArr,adjList);
            }
       }
       return components;
    };
};



