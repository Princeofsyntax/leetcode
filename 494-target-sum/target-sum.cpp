class Solution {
public:
      int solve(vector<int> &nums, int target)
    {
        // create map
        map<pair<int, int>, int> dp;
        dp[{nums.size(), 0}] = 1; // base case

        // target value also can go to negative --> (target - sum of all elements) = target range decider
        int total = 0;
        for (auto num : nums)
        {
            total += num; // total sum
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // range of target --> -total to +total
            for (int sum = -total; sum <= total; sum++)
            {
                int plus = dp.find({i + 1, sum - nums[i]}) != dp.end() ? dp[{i + 1, sum - nums[i]}] : 0;
                int minus = dp.find({i + 1, sum + nums[i]}) != dp.end() ? dp[{i + 1, sum + nums[i]}] : 0;

                // store
                dp[{i, sum}] = plus + minus;
            }
        }
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solve(nums, target);
    }

};