#include <vector>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        
        function<bool(int, int)> dfs = [&](int node, int parent) {
            vis[node] = true;
            
            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    if(dfs(neighbor, node)) return true;
                }
                else if(neighbor != parent) return true;
            }
            
            return false;
        };
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1)) return true;
            }
        }
        return false;
    }
};