#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res, vis(V, 0);
        function<void(int)> traverse = [&](int v) {
            vis[v] = 1;
            res.push_back(v);
            for (int u : adj[v])
                if (!vis[u]) traverse(u);
        };
        for (int i = 0; i < V; i++)
            if (!vis[i]) traverse(i);
        return res;
    }
};