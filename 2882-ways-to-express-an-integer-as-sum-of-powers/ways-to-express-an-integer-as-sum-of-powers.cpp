class Solution {
public:
    const int MOD = 1e9 + 7;
    // dp[i][sum] = ways using numbers starting from i to make sum
    long long dp[301][301];  
    
    long long power(int base, int exp) {
        long long result = 1;
        while (exp > 0) {
            result *= base;
            exp--;
        }
        return result;
    }
    
    long long solve(int curr, int n, int x) {
        if (n == 0) return 1; // Found valid combination
        if (n < 0) return 0;  // Exceeds target
        if (curr > 300) return 0;
        if (dp[curr][n] != -1) return dp[curr][n];
        
        long long ways = 0;
        long long p = power(curr, x);
        
        if (p <= n) {
            // Take current number
            ways += solve(curr + 1, n - p, x);
            ways %= MOD;
        }
        // Skip current number
        ways += solve(curr + 1, n, x);
        ways %= MOD;
        
        return dp[curr][n] = ways;
    }
    
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(1, n, x);
    }
};
