class Solution {
public:
    bool isEven(int num) {
        return (num % 2 == 0); // even means lsb or parity as 0 
    }

    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        for (int i = 0; i < n - 1; i++) {
            if (isEven(nums[i]) == isEven(nums[i + 1])) {
                return false;
            }
        }
        return true; 
    }
};