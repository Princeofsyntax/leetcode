class Solution {
public:
     int solve(vector<int> &nums, vector<vector<int>> &dp)
    {
        // initialise the base case of dp --> when (start = end)-->diagonal-->initialise with nums[start]
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][i] = nums[i];
        }
        int i = nums.size(); // to manage diffByEnd
        // move opposite to top down dp
        for (int start = nums.size() - 1; start >= 0; start--)
        {
            // Begin where start == end --> filling in dp will be right side of diagonal in 2D MATRIX formed
            for (int end = i; end < nums.size(); end++)
            {
                int diffByStart = nums[start] - dp[start + 1][end];
                int diffByEnd = nums[end] - dp[start][end - 1];
                // store
                dp[start][end] = max(diffByEnd, diffByStart);
            }
            i--; // so that end begin from diagonal
        }
        return dp[0][nums.size() - 1];
    }

    bool predictTheWinner(vector<int> &nums)
    {
        // create dp 2D
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1)); // extra to manage diffByEnd
        return solve(nums, dp) >= 0;
    }
};