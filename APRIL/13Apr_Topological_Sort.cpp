#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        vector<int> result;
        
        function<void(int)> dfs = [&](int node) {
            vis[node] = true;
            
            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    dfs(neighbor);
                }
            }
            
            result.push_back(node);
        };
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};