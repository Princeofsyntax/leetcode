class Solution {
public:
      int solve(string &s1, string &s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        // initialise base case when one of the string is empty
        // we have to take various condition --> s1 may be empty and s2 may be not --> so fill dp accordingly and vice versa
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()]; // current + remaining costs
        }
        for (int i = s2.size() - 1; i >= 0; i--)
        {
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i + 1]; // current + remaining costs
        }

        // now solution
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                int cost = 0;
                if (s1[i] == s2[j])
                {
                    cost = dp[i + 1][j + 1];
                }
                else
                {
                    // remove one-one character from both strings via recursion
                    int cost1 = s1[i] + dp[i + 1][j];
                    int cost2 = s2[j] + dp[i][j + 1];
                    cost = min(cost1, cost2);
                }
                // store and return
                dp[i][j] = cost;
            }
        }
        return dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2)
    {
        return solve(s1, s2);
    }
};