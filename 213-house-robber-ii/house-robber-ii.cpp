class Solution {
public:
     int solveUsingMem(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0)
            return 0; 
        if(n == 0)
            return nums[0]; 

        if(dp[n] != -1){
            return dp[n];
        }
        
        int include = solveUsingMem(nums, n-2,dp) + nums[n];
        int exclude = solveUsingMem(nums, n-1,dp) + 0;
        
        dp[n] = max(include, exclude);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int>nums1(nums.begin()+1, nums.end());
        vector<int>nums2(nums.begin(), nums.end()-1);

        int n1 = nums1.size()-1;
        int n2 = nums2.size()-1;
        vector<int>dp(n1+1, -1); 
        int ans1 = solveUsingMem(nums1,n1,dp);
        dp.clear();
        dp.resize(n2+1, -1);
        int ans2 = solveUsingMem(nums2,n2,dp);
        return max(ans1, ans2);
    }
};