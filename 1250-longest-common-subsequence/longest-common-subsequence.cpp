class Solution {
public:
        int solveUsingTabulation(string &a, string &b)
        {
            // create dp
            vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

            // move opposite to top down approach
            for (int i = a.length() - 1; i >= 0; i--)
            {
                for (int j = b.length() - 1; j >= 0; j--)
                {
                    int ans = 0;
                    if (a[i] == b[j])
                    {
                        // match
                        ans = 1 + dp[i + 1][j + 1];
                    }
                    else
                    {
                        // do not match
                        ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                    }
                    // store answer
                    dp[i][j] = ans;
                }
            }
            return dp[0][0]; // when u dont get what to return then check what is passed or where for loop goes to
        }

    int longestCommonSubsequence(string text1, string text2)
        {
            return solveUsingTabulation(text1, text2);
        }
};