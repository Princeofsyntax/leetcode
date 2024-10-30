class Solution {
public:
      int solveOptimal(vector<int> &arr, vector<int> &lis)
    {
        if (arr.size() == 0)
            return 0;
        vector<int> ans;

        lis.push_back(1); // as current element will be counted in every case

        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > ans.back())
            {
                // include
                ans.push_back(arr[i]);
                lis.push_back(ans.size());
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin(); // provides the required index
                ans[index] = arr[i];
                lis.push_back(index + 1);
            }
        }
        return ans.size();
    }

    int minimumMountainRemovals(vector<int> &nums)
    {
        vector<int> lis, lds; // longest increasing subsequence and longest decreasing subsequence
        // make lis and lds array by taking each element as pivot
        solveOptimal(nums, lis);
        // reverse to get lds
        reverse(nums.begin(), nums.end());
        solveOptimal(nums, lds);

        int largestMountainLength = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
            {
                // as lds was reversed
                // 1 means not forming mountain
                continue;
            }
            largestMountainLength = max(largestMountainLength, lis[i] + lds[nums.size() - i - 1] - 1);
        }
        int minRemovals = nums.size() - largestMountainLength;
        return minRemovals;
    }
};