// 23. Unique Number II
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNum(vector<int>& A) {
        int x = 0, a = 0, b = 0;
        for (int n : A) x ^= n;
        for (int n : A) (n & (x & -x) ? a : b) ^= n;
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
};