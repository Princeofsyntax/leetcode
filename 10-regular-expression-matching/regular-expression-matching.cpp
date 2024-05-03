class Solution {
public:
    // Function to check if string 's' matches the pattern 'p'.
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
      
        // Base case: empty string matches with empty pattern
        dp[0][0] = true;
      
        // Fill the dp table
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
              
                // If the pattern character is '*', it can either eliminate the character and its predecessor
                // or if the string is not empty and the character matches, include it
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if (i > 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                // If the current characters match (or the pattern has '.'), then the result
                // is determined by the previous states of both the string and pattern
                else if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
      
        // Return the result at the bottom-right corner of the dp table
        return dp[m][n];
    }
};