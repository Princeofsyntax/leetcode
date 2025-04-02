class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;
        
        vector<int> maxRight(n, 0);
        maxRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], nums[i]);
        }
        
        int maxLeft = nums[0];
        for (int j = 1; j < n - 1; ++j) {
            if (maxLeft > nums[j]) {
                maxValue = max(maxValue, (long long)(maxLeft - nums[j]) * maxRight[j + 1]);
            }
            maxLeft = max(maxLeft, nums[j]);
        }
        
        return maxValue;
    }
};