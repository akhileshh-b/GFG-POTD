// 24. Unique Number III
#include <vector>
using namespace std;

class Solution {
public:
    int getSingle(vector<int>& arr) {
        int ones = 0, twos = 0;
        for (int num : arr) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};