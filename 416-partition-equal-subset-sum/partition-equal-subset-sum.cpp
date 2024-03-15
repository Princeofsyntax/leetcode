class Solution {
public:
    bool solveUsingSpaceOpt(vector<int> &nums, int target)
    {
        int n = nums.size();
        // step1. create 2 vectors
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        // base case --> store 1 at 0th position
        curr[0] = 1;
        next[0] = 1;

        // now move opposite to top down --> n-1 to 0
        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 1; t <= target; t++)
            {
                int include = 0; // u can take bool also but integer 0 means false and rest are true so no issue
                if (t - nums[index] >= 0)
                    include = next[t - nums[index]];

                int exclude = next[t];

                // store the answer
                curr[t] = (include || exclude);
            }
            // shifting
            next = curr; // as we are moving opposite
        }
        return next[target]; // as we wre moving from n-1 to 0 ; answer will be present at 0th row
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum & 1)
            return false; // odd case
        int target = sum / 2;
        bool ans = solveUsingSpaceOpt(nums, target);
        return ans;
    }

};