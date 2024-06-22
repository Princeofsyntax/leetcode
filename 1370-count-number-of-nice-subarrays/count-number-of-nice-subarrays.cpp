class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        int odd_count = 0;
        int result = 0;

        // Initialize count for zero odd numbers seen
        count[0] = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                odd_count++;
            }

            if (odd_count >= k) {
                result += count[odd_count - k];
            }

            count[odd_count]++;
        }

        return result;
    }
};