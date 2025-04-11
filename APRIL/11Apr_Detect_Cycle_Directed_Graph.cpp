#include <vector>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0), pathVis(V, 0);
        
        function<bool(int)> dfs = [&](int node) {
            vis[node] = pathVis[node] = 1;
            
            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    if(dfs(neighbor)) return true;
                }
                else if(pathVis[neighbor]) return true;
            }
            
            pathVis[node] = 0;
            return false;
        };
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i)) return true;
            }
        }
        return false;
    }
};