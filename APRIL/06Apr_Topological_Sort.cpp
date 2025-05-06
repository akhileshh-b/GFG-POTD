#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> in(V, 0), res;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!in[i])
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u])
                if (--in[v] == 0)
                    q.push(v);
        }
        return res;
    }
};