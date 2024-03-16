class Solution {
public:
    int solveUsingTabulation(int n)
    {
        // create dp array --> n+2 to avoid any issue
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // 0 is stored so base case is already considered

        // move opposite to top down
        for (int start = n; start >= 1; start--)
        {
            for (int end = 1; end <= n; end++)
            {
                if (start >= end)
                {
                    continue; // as in base case this cndition must return 0
                }
                else
                {
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++)
                    {
                        ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                    }
                    // store in dp
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int ans = solveUsingTabulation(n);
        return ans;
    }
};