class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());
        int maxLen = 0, currLen = 0;
        for(const auto& num : nums){
            if(num == maxVal)currLen++;
            else currLen = 0;
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};