class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        for(const auto&num : nums){
            maxVal = max(maxVal, num);
        }

        int longest = 0, currentLongest = 0;
        for(const auto&num : nums){
            if(num == maxVal){
                currentLongest++;
                longest = max(longest, currentLongest);
            }
            else{
                currentLongest = 0;
            }
        }
        return longest;
    }
};