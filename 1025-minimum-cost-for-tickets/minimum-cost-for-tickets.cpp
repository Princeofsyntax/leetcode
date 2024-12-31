class Solution {
public:
    int helper(int i, vector<int>& days, vector<int>& cost, vector<int>&dp){
        if(i >= days.size()) return 0;
        if(dp[i] != -1)return dp[i];
        //for one day
        int cost1 = cost[0] + helper(i+1, days, cost, dp);
        //for 7 days
        int index = i;
        int till = days[i] + 6;
        while(index < days.size() && days[index] <= till) index++;
        int cost2 = cost[1] + helper(index, days, cost, dp);
        //for one month
        index = i;
        till = days[i] + 29;
        while(index < days.size() && days[index] <= till) index++;
        int cost3 = cost[2] + helper(index, days, cost, dp);

        return dp[i] = min({cost1, cost2, cost3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs){
        vector<int>dp(days.size(), -1);
        return helper(0, days, costs, dp);
    }
};