class Solution {
public:
    int helper(int index, int buy, vector<int>&prices, int n, vector<vector<int>>&dp){
        // base case
        if(index >= n) return 0;
        if(dp[index][buy]!= -1) return dp[index][buy];
        if(buy){
            return dp[index][buy] = max(-prices[index] + helper(index+1, !buy, prices, n, dp) , 0 + helper(index+1, buy, prices, n, dp));
        }
        else{
            return dp[index][buy] = max(prices[index] + helper(index+2, !buy, prices, n, dp) , 0 + helper(index+1, buy, prices, n, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return helper(0, 1, prices, n, dp);
    }
};