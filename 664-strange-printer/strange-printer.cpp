class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; // Base case: single character
        }

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length <= n; i++) {
                int j = i + length - 1;
                dp[i][j] = dp[i][j-1] + 1; // Start with assuming the last char requires one extra print
                
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + (k+1 <= j-1 ? dp[k+1][j-1] : 0));
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
