class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        vector<long long> dp(k + 1 , 0), buy(k , -1e9), sell(k , 0);
        for(int i = 0, n = prices.size(); i < n; ++i){
            int price = prices[i];
            for(int j = k; j; --j){
                dp[j] = max(dp[j] , max(buy[j - 1] + price , sell[j - 1] - price));
                buy[j - 1] = max(buy[j - 1] , dp[j - 1] - price);
                sell[j - 1] = max(sell[j - 1] , dp[j - 1] + price);
            }
        }
        long long res = 0;
        for(int i = 0; i <= k; ++i) res = max(res , dp[i]);
        return res;
    }
};