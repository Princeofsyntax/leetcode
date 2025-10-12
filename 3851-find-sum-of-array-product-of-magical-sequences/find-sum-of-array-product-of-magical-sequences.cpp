class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        long long MOD = 1e9 + 7;
        return power(n, MOD - 2);
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        vector<long long> fact(m + 1);
        vector<long long> invFact(m + 1);
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= m; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
            invFact[i] = modInverse(fact[i]);
        }

        vector<vector<long long>> num_pow_div_fact(n, vector<long long>(m + 1));
        for (int j = 0; j < n; ++j) {
            long long current_pow = 1;
            for (int c = 0; c <= m; ++c) {
                num_pow_div_fact[j][c] = (current_pow * invFact[c]) % MOD;
                current_pow = (current_pow * nums[j]) % MOD;
            }
        }
        
        int max_carry = m / 2;
        vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(max_carry + 1, vector<long long>(k + 1, 0)));
        dp[0][0][0] = 1;

        for (int j = 0; j < n; ++j) {
            vector<vector<vector<long long>>> next_dp(m + 1, vector<vector<long long>>(max_carry + 1, vector<long long>(k + 1, 0)));
            for (int i = 0; i <= m; ++i) {
                for (int carry = 0; carry <= i / 2; ++carry) {
                    for (int b = 0; b <= k; ++b) {
                        if (dp[i][carry][b] == 0) continue;
                        for (int c = 0; c <= m - i; ++c) {
                            int i_new = i + c;
                            int val = c + carry;
                            int b_new = b + (val % 2);
                            if (b_new > k) continue;
                            int carry_new = val / 2;
                            if (carry_new > i_new / 2) continue;

                            long long term = num_pow_div_fact[j][c];
                            long long contribution = (dp[i][carry][b] * term) % MOD;
                            next_dp[i_new][carry_new][b_new] = (next_dp[i_new][carry_new][b_new] + contribution) % MOD;
                        }
                    }
                }
            }
            dp = next_dp;
        }
        
        long long ans = 0;
        for (int carry = 0; carry <= m / 2; ++carry) {
            int carry_bits = __builtin_popcount(carry);
           
            if (k >= carry_bits) {
                int b = k - carry_bits;
                ans = (ans + dp[m][carry][b]) % MOD;
            }
        }

        long long final_ans = (ans * fact[m]) % MOD;
        return (int)final_ans;
    }
};