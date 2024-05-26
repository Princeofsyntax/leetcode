class Solution {
public:
    int MOD = 1e9 + 7;
    int checkRecord(int n) {
        // Define 'll' as shorthand for 'long long' type
        using ll = long long;
        // Create a 3D vector to hold the state information
        // dp[i][j][k] represents the number of valid sequences of length i
        // where j tracks the absence count (0 for no A, 1 for one A)
        // and k tracks the late count (0, 1, or 2 consecutive L's)
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(3)));

        // base cases for first day
        dp[0][0][0] = 1; // P
        dp[0][0][1] = 1; // L
        dp[0][1][0] = 1; // A

        for (int i = 1; i < n; ++i) {
            // For A: append A after sequences that do not contain A ('j' == 0)
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;

            // For L: append L after sequences ending in no L or 1 L
            dp[i][0][1] = dp[i - 1][0][0]; // no L followed by L
            dp[i][0][2] = dp[i - 1][0][1]; // 1 L followed by another L
            dp[i][1][1] = dp[i - 1][1][0]; // no L followed by L, already contains A
            dp[i][1][2] = dp[i - 1][1][1]; // 1 L followed by another L, already contains A

            // For P: append P after any sequence
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            // for sequences that already contain A, append P
            dp[i][1][0] = (dp[i][1][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
        }

        // Calculate the final result by summing up all possible sequences of length 'n'
        ll result = 0;
        for (int absence = 0; absence < 2; ++absence) {
            for (int late = 0; late < 3; ++late) {
                result = (result + dp[n - 1][absence][late]) % MOD;
            }
        }
        return result;
    }
};