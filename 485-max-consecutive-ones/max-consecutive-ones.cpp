class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0; 
        int c_ones = 0, max_c_ones = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) { 
                int j = i;
                c_ones = 0; 
                while (j < nums.size() && nums[j] == 1) {
                    c_ones++;
                    j++;
                }
                max_c_ones = max(max_c_ones, c_ones); 
                i = j - 1; 
            }
        }
        return max_c_ones;
    }
};