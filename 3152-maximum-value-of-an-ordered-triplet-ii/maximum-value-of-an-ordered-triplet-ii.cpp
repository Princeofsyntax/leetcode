class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }
        long long maxValue = 0;
        for (int j = 1; j < n - 1; j++) {
            int leftMax = prefixMax[j - 1];
            int rightMax = suffixMax[j + 1]; 
            long long value = ((long long)leftMax - (long long)nums[j]) * (long long)rightMax;
            maxValue = max(maxValue, value);
        }
        return maxValue;
    }
};