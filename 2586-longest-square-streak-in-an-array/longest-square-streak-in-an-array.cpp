class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longestStreak = 0;
        
        for (int num : nums) {
            int streak = 0;
            long long current = num;  
            while (numSet.find(current) != numSet.end()) {
                streak++;
                current = current * current; 
                if (current > 1e5) break;
            }
            
            if (streak >= 2) {
                longestStreak = max(longestStreak, streak);
            }
        }
        
        return (longestStreak >= 2) ? longestStreak : -1;
    }
};