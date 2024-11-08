class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer(n);
        int cumulative_xor = 0;
        for (int num : nums) {
            cumulative_xor ^= num;
        }
        int max_possible_xor = (1 << maximumBit) - 1;

        for (int i = 0; i < n; ++i) {
            answer[i] = max_possible_xor ^ cumulative_xor;
            cumulative_xor ^= nums[n - 1 - i];
        }
        return answer;
    }
};