#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        // Relax all edges V-1 times
        for(int i = 1; i <= V-1; i++) {
            for(auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative weight cycles
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                return vector<int>(1, -1); // Negative cycle exists
            }
        }
        
        // Replace INT_MAX with 100000000 for unreachable nodes
        for(int& d : dist) {
            if(d == INT_MAX) d = 100000000;
        }
        
        return dist;
    }
};