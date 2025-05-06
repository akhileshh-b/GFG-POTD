// 25. Majority Element
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(int arr[], int n) {
        int count = 0, cand;
        for (int i = 0; i < n; i++) {
            if (!count) cand = arr[i];
            count += arr[i] == cand ? 1 : -1;
        }
        count = 0;
        for (int i = 0; i < n; i++) if (arr[i] == cand) count++;
        return count > n/2 ? cand : -1;
    }
};