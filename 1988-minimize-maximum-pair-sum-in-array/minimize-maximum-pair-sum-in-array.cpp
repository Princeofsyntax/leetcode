class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxPairSum = INT_MIN;
        int i = 0, j = n-1;
        while(i < j){
            maxPairSum = max(maxPairSum,nums[i]+nums[j]);
            i++,j--;
        }
        return maxPairSum;
    }
};