class Solution {
  public:
    Node *primeList(Node *head) {
        vector<bool> isPrime(10051, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= 10050; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 10050; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = 2; i <= 10050; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        Node* curr = head;
        while (curr) {
            int val = curr->val;
            if (isPrime[val]) {
                curr = curr->next;
                continue;
            }
            int idx = lower_bound(primes.begin(), primes.end(), val) - primes.begin();
            int high = (idx < primes.size()) ? primes[idx] : INT_MAX;
            int low = (idx > 0) ? primes[idx - 1] : INT_MAX;
            if (abs(high - val) < abs(val - low)) curr->val = high;
            else if (abs(high - val) > abs(val - low)) curr->val = low;
            else curr->val = min(high, low);
            curr = curr->next;
        }
        return head;
    }
}; 