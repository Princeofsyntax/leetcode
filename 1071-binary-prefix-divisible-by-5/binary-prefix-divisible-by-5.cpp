class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans(n);
        int rem = 0;
        //check for remainder whenever we add any binary digit
        for(int i = 0; i < n; i++){
            rem = (rem * 2 + nums[i]) % 5;   
            ans[i] = (rem == 0);
        }
        return ans;
    }
};