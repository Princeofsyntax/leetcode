class Solution {
public:
    static const int MOD = 1000000007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int count = 0;
        while (n > 0) {
            if (n & 1) powers.push_back(1 << count);
            n >>= 1;
            count++;
        }
        sort(powers.begin(), powers.end());
        int m = powers.size();

        vector<long long> product(m);
        product[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++)
            product[i] = (product[i-1] * powers[i]) % MOD;

        vector<int> ans;
        for (auto &q : queries) {
            int left = q[0], right = q[1];
            if (left == 0) {
                ans.push_back(product[right]);
            } else {
                long long inv = modPow(product[left-1], MOD-2);
                ans.push_back((product[right] * inv) % MOD);
            }
        }
        return ans;
    }
};
