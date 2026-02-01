class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minSum = nums[0];
        nums[0] = INT_MAX;
        sort(nums.begin(), nums.end());
        minSum += nums[0] + nums[1];
        return minSum;
    }
};