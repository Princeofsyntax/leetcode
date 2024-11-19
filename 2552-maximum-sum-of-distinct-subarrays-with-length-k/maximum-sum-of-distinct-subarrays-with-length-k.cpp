class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, currentSum = 0;
        set<int> st;
        for (int i = 0, j = 0; j < n; ++j) {
            currentSum += nums[j];
            while (st.find(nums[j]) != st.end()) {
                currentSum -= nums[i];
                st.erase(nums[i]);
                ++i;
            }
            st.insert(nums[j]);
            if (j - i + 1 > k) {
                currentSum -= nums[i];
                st.erase(nums[i]);
                ++i;
            }
            if (j - i + 1 == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
