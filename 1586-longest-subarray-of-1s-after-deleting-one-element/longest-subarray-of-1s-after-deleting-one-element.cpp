class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (right < n) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Calculate the length of the current window, which is right - left + 1
            // Since we need to delete one element, we consider the window size as (right - left)
            maxLength = max(maxLength, right - left);

            right++;
        }

        return maxLength;
    }
};