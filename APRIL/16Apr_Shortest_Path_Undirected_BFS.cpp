#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create adjacency list
        vector<vector<int>> adj(N);
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Initialize distances
        vector<int> dist(N, INT_MAX);
        queue<int> q;
        
        // Start BFS from source
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(int neighbor : adj[node]) {
                if(dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
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