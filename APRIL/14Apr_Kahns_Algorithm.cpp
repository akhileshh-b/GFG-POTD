#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0), result;
        queue<int> q;
        
        // Calculate in-degree for each vertex
        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }
        
        // Add vertices with 0 in-degree to queue
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return result;
    }
};