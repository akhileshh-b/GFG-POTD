#include <vector>
#include <functional>
using namespace std;

class Solution{
public:
    int countIslands(vector<vector<char>>& g){
        int n = g.size(), m = g[0].size(), ans = 0;
        function<void(int,int)> f = [&](int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 'W') return;
            g[i][j] = 'W';
            for(int a = -1; a <= 1; a++)
                for(int b = -1; b <= 1; b++)
                    f(i + a, j + b);
        };
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == 'L') { ans++; f(i, j); }
        return ans;
    }
};