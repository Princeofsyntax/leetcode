class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int MAXN = 1e6 + 1;
        vector<bool> is_prime(MAXN, true);
        vector<int> primes;
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i < MAXN; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < MAXN; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> prime_list;
        for (int p : primes) {
            if (p > right) break;
            if (p >= left) prime_list.push_back(p);
        }
        
        if (prime_list.size() < 2) return {-1, -1};
        
        int min_diff = INT_MAX;
        pair<int, int> closest_pair = {-1, -1};
        
        for (int i = 1; i < prime_list.size(); ++i) {
            int diff = prime_list[i] - prime_list[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                closest_pair = {prime_list[i - 1], prime_list[i]};
            }
        }
        return {closest_pair.first, closest_pair.second};
    }
};