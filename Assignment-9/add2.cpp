#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Min-heap: {cost, {row, col}}
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> 
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0,0}});

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()) {
        auto curr = pq.top(); pq.pop();
        int cost = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;

        // If we reach the goal, we can return immediately
        if (x == m-1 && y == n-1) return cost;

        // If cost is outdated, skip
        if (cost > dist[x][y]) continue;

        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    return dist[m-1][n-1];
}
