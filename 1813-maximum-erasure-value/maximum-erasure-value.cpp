class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int ans = 0;
        int curr_sum = 0;
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n) {
            if (freq[nums[j]] > 0) {
                curr_sum -= nums[i];
                freq[nums[i]]--;
                i++;
            } else {
                curr_sum += nums[j];
                freq[nums[j]]++;
                ans = max(ans, curr_sum);
                j++;
            }
        }
        return ans;
    }
};