class Solution {
public:
    int solve(vector<int> &prices, int i, int buy, int k, vector<vector<vector<int>>> &dp)
    {
        // calculate dp[0] using dp[1] and move for next dp[1]
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int limit = 1; limit < k + 1; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        int buyItProfit = -prices[i] + dp[1][false][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }
                    else
                    {
                        // sell
                        int sellItProfit = prices[i] + dp[1][true][limit - 1]; // when buy and sell pair is completed then limit  = limit-1
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }
                    // store ans
                    dp[0][buy][limit] = profit;
                }
            }
            // shifting
            dp[1] = dp[0];
        }
        return dp[0][1][k]; // answer present from where top down was initiated
    }

    int maxProfit(int k, vector<int> &prices)
    {
        // create 3D dp array --> with 2 rows only
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k + 1, 0))); // limit can be 0,1,2
        return solve(prices, 0, 1, k, dp);                                               // limit =  2
    }
};