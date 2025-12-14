class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int end1 = 0, end2 = 0;
        for(int i = 0; i < k; i++){
            end1 += nums[i];
            end2 += nums[n-i-1];
        }
        return abs(end1-end2);
    }
};