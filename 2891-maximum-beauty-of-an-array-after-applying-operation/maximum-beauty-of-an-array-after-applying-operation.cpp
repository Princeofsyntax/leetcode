class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 0;
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            maxBeauty = max(maxBeauty, right - left + 1);
        }
        return maxBeauty;
    }
};