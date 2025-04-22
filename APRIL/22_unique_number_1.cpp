// 22. Unique Number I
#include <vector>
using namespace std;

class Solution {
public:
    int findUnique(vector<int>& a) {
        int r = 0;
        for (int x : a) r ^= x;
        return r;
    }
};