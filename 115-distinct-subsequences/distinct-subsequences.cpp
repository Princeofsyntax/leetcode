class Solution {
public:
    int solve(string &s, string &t)
    {
        // create 2D dp
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        // handle base case
        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][t.size()] = 1;
        }

        // proceed
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = t.size() - 1; j >= 0; j--)
            {
                long long ans = 0;
                if (s[i] == t[j])
                {
                    // consider the current character
                    ans += dp[i + 1][j + 1];
                }
                // neglect the current character
                ans += dp[i + 1][j];

                // store and return
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int numDistinct(string s, string t)
    {
        return solve(s, t);
    }
};