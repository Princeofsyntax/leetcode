class Solution {
public:
    int minCost_ticketHelper(vector<int> &days, vector<int> &costs, int i, vector<int> &dp)
    {
        // base case
        dp[days.size()] = 0;

        // move opposite to top down
        for (int i = days.size() - 1; i >= 0; i--)
        {
            int cost1 = costs[0] + dp[i + 1];

            // 7 days pass taken
            int passEndDay = days[i] + 7 - 1;
            int j = i;
            while (j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30 days pass taken
            passEndDay = days[i] + 30 - 1;
            j = i;
            while (j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost30 = costs[2] + dp[j];
            // 2.store the answer
            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // 1.create dp array
        vector<int> dp(days.size() + 1, -1); // because i is varying and that relies on days array
        return minCost_ticketHelper(days, costs, 0, dp);
    }
};