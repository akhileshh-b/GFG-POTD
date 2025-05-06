class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        int n = s.size(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        vector<int> freq(256, 0);
        while (j < n) {
            if (++freq[s[j++]] == 1) c++;
            while (c == d) {
                res = min(res, j - i);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
}; 