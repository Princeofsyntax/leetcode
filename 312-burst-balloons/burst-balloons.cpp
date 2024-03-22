class Solution {
public:
      int solve(vector<int> &nums)
    {
        // create dp 2D
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        int n = nums.size() - 2;
        for (int start = n; start >= 1; start--)
        {
            for (int end = start; end <= n; end++)
            {
                // end is begining with start to avoid base case (start > end must return 0)
                int coins = INT_MIN;
                for (int i = start; i <= end; i++)
                {
                    coins = max(coins, nums[start - 1] * nums[i] * nums[end + 1] + dp[start][i - 1] + dp[i + 1][end]);
                }
                // store and return
                dp[start][end] = coins;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int> &nums)
    {
        // insert 1 at begin and end
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        return solve(nums);
    }
};