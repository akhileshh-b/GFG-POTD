// 21. Missing in Array
#include <vector>
using namespace std;

class Solution {
public:
    int missingNum(vector<int>& a) {
        int x = 0, n = a.size() + 1;
        for (int i = 0; i < a.size(); ++i) x ^= a[i] ^ (i + 1);
        return x ^ n;
    }
};