class Solution {
public:
    int dfs(int index, int prev, vector<int>&nums, int n, vector<vector<int>>&dp){
        if(index == n) return 0;
        if(dp[index][prev+1] != -1)return dp[index][prev+1];
        int notTake = dfs(index+1, prev, nums, n, dp);
        int take = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            take += 1 + dfs(index+1, index, nums, n, dp);
        }
        return dp[index][prev+1] = max(take, notTake); // prev+1 to avoid -1 index issue
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return dfs(0,-1,nums,n,dp);
    }
};