class Solution {
public:
    int helper(int i, vector<int>&coins, int amount, vector<vector<int>>&dp){
        if (amount == 0) return 0; 
        if (i == 0) return (amount % coins[0] == 0) ? amount / coins[0] : INT_MAX; 
        if(dp[i][amount] != -1)return dp[i][amount];
        int notTake = helper(i - 1, coins, amount, dp); 
        int take = INT_MAX;
        if (coins[i] <= amount) {
            int res = helper(i, coins, amount - coins[i], dp);  
            if (res != INT_MAX) take = 1 + res;  
        }

        return dp[i][amount] = min(take, notTake);  

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int result = helper(n - 1, coins, amount, dp);
        return result == INT_MAX ? -1 : result;  
    }
};