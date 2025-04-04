#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> p(V, -1);
        function<int(int)> f = [&](int x){ return p[x] < 0 ? x : p[x] = f(p[x]); };
        for(auto &e : edges){
            int a = f(e[0]), b = f(e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
};