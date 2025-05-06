#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        vector<int> in(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), in[e[1]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!in[i]) q.push(i);
        int c = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); c++;
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        return c != V;
    }
};