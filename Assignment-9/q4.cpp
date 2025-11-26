//dijkstras algo
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int N, vector<vector<pair<int,int>>>& adj, int start) {
    const int INF = 1e9;
    vector<int> dist(N + 1, INF);

    // Min-heap: {distance, node}
    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
