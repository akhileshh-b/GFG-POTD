#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int N, vector<vector<int>>& edges) {
        // Create adjacency list with weights
        vector<vector<pair<int, int>>> adj(N);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<int> dist(N, INT_MAX);
        vector<bool> vis(N, false);
        vector<int> order;
        
        // Topological sort using DFS
        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            for(auto& [neighbor, weight] : adj[node]) {
                if(!vis[neighbor]) {
                    dfs(neighbor);
                }
            }
            order.push_back(node);
        };
        
        // Get topological order
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        reverse(order.begin(), order.end());
        
        // Calculate shortest paths
        dist[0] = 0;
        for(int node : order) {
            if(dist[node] != INT_MAX) {
                for(auto& [neighbor, weight] : adj[node]) {
                    if(dist[node] + weight < dist[neighbor]) {
                        dist[neighbor] = dist[node] + weight;
                    }
                }
            }
        }
        
        // Replace INT_MAX with -1 for unreachable nodes
        for(int& d : dist) {
            if(d == INT_MAX) d = -1;
        }
        
        return dist;
    }
};