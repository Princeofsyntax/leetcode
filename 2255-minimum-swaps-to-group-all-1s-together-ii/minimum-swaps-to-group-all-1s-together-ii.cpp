class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = 0;
        
        for (int num : nums) {
            if (num == 1) countOnes++;
        }
        
        if (countOnes == 0) return 0;
        
        int maxOnesInWindow = 0, currentOnes = 0;
        
        for (int i = 0; i < countOnes; ++i) {
            if (nums[i] == 1) currentOnes++;
        }
        
        maxOnesInWindow = currentOnes;
        
        for (int i = countOnes; i < n + countOnes; ++i) {
            if (nums[i % n] == 1) currentOnes++;
            if (nums[(i - countOnes) % n] == 1) currentOnes--;
            
            maxOnesInWindow = max(maxOnesInWindow, currentOnes);
        }
        
        return countOnes - maxOnesInWindow;
    }
};
