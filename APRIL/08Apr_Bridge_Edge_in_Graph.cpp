#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs(adj, v, vis);
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c))
                adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        dfs(adj, c, vis);
        return !vis[d];
    }
};