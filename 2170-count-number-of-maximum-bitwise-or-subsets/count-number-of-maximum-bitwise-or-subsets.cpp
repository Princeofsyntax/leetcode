class Solution {
public:
        int findMaxOR(const vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;  
        }
        return maxOR;
    }

    void countMaxORSubsets(const vector<int>& nums, int idx, int currentOR, int maxOR, int& count) {
        if (idx == nums.size()) {
            if (currentOR == maxOR) {
                count++;
            }
            return;
        }
        
        countMaxORSubsets(nums, idx + 1, currentOR | nums[idx], maxOR, count);
        
        countMaxORSubsets(nums, idx + 1, currentOR, maxOR, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = findMaxOR(nums);  
        int count = 0;
        countMaxORSubsets(nums, 0, 0, maxOR, count); 
        return count;
    }
};