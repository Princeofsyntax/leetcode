class Solution {
public:
    int solve(vector<int> &prices, vector<vector<int>> &dp)
    {
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyItProfit = -prices[i] + dp[1][0];
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit, skipProfit);
                }
                else
                {
                    // sell
                    int sellItProfit = prices[i] + dp[1][1];
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                // store the answer
                dp[0][buy] = profit;
            }
            // shifting
            dp[1] = dp[0];
        }
        return dp[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
        // 1.create dp
        vector<vector<int>> dp(2, vector<int>(2, 0)); // 2 rows are needed
        return solve(prices, dp);
    }
};