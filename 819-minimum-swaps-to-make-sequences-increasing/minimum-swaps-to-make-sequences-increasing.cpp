class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, 0));

        for (int i = nums1.size() - 1; i >= 1; i--)
        {
            // swap or not swap
            for (int j = 1; j >= 0; j--)
            {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];
                if (j)
                    swap(prev1, prev2);
                int swap = INT_MAX;
                int noSwap = INT_MAX;
                // swap condition
                if (prev1 < nums2[i] && prev2 < nums1[i])
                {
                    swap = 1 + dp[i + 1][1];
                }
                // no swap
                if (prev1 < nums1[i] && prev2 < nums2[i])
                {
                    noSwap = dp[i + 1][0];
                }

                // store
                dp[i][j] = min(swap, noSwap);
            }
        }
        return dp[1][0]; // 1 is taken as we have inserted extra row at begining
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // we have to handle the case of previous as we wil move bottom to up --> at index 0 , we need prev --> -1
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        // after inserting --> indexing will change and index 0 will be previous --> therefore in function the loop will goes to index 1 AND NOT 0
        return solve(nums1, nums2);
    }
};