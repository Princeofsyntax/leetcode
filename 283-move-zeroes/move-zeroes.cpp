class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        // Move all non-zero elements to the front of the array
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }

    }
};