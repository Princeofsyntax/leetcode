class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    // __builtin_popcount counts the number of set bits (1s) 
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                        swap(nums[j], nums[j + 1]);  
                    } else {
                        return false; 
                    }
                }
            }
        }
        return true;  
    }
};