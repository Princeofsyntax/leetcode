class Solution {
public:
    void convertStrsToNumStrs(vector<string> &strs, vector<pair<int, int>> &numStrs)
    {
        for (auto str : strs)
        {
            int zeros = 0;
            int ones = 0;
            for (auto ch : str)
            {
                if (ch == '0')
                    ++zeros;
                else
                    ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }
    
    int solve(vector<pair<int, int>> &numStrs, int i, int m, int n)
    {
        vector<vector<vector<int>>> dp(numStrs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = numStrs.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    int zeros = numStrs[i].first;
                    int ones = numStrs[i].second;

                    int include = 0;
                    int exclude = 0;
                    if (j - zeros >= 0 && k - ones >= 0)
                    {
                        include = 1 + dp[i + 1][j - zeros][k - ones];
                    }
                    exclude = dp[i + 1][j][k];

                    // store
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> numStrs;
        convertStrsToNumStrs(strs, numStrs);
        return solve(numStrs, 0, m, n);
    }
};