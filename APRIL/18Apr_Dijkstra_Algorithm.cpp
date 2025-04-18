#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Priority queue to store {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);
        
        // Distance to source is 0
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Check all neighbors
            for(auto& edge : adj[node]) {
                int neighbor = edge[0];
                int weight = edge[1];
                
                if(d + weight < dist[neighbor]) {
                    dist[neighbor] = d + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        
        return dist;
    }
};