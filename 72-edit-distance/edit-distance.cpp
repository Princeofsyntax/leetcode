class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create a 2D dp array with (m+1) rows and (n+1) columns
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Initialize the dp array
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i; // Deleting all characters from word1 to match an empty word2
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j; // Inserting all characters into an empty word1 to match word2
        }

        // Fill the dp array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // Characters match, no new operation needed
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1,    // Delete a character from word1
                                    dp[i][j - 1] + 1,    // Insert a character into word1
                                    dp[i - 1][j - 1] + 1 // Replace a character in word1
                                   });
                }
            }
        }

        return dp[m][n];
    }
};