class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int length, int low, int high, int zero, int one, vector<int>& dp) {
        if (length > high) return 0;
        if (dp[length] != -1) return dp[length];
        // Count the current string if it's within [low, high]
        int count = (length >= low) ? 1 : 0;
        // Recursively append '0's and '1's
        count = (count + dfs(length + zero, low, high, zero, one, dp)) % MOD;
        count = (count + dfs(length + one, low, high, zero, one, dp)) % MOD;
        return dp[length] = count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return dfs(0, low, high, zero, one, dp);
    }
};