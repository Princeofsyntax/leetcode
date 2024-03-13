class Solution {
public:
    //n-->represent index of current house

    int solveUsingMem(vector<int>& nums, int n, vector<int>& dp){
        if(n < 0)
            return 0; //as no house to rob
        if(n == 0)
            return nums[0]; //1 house is present

        //3.check if value already present
        if(dp[n] != -1){
            return dp[n];
        }
        
        //include (move 2 steps) and exclude (move 1 step)
        int include = solveUsingMem(nums, n-2,dp) + nums[n];
        int exclude = solveUsingMem(nums, n-1,dp) + 0;
        
        //2.store 
        dp[n] = max(include, exclude);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        //include exclude based + dp
        int n = nums.size()-1;
        //1.create dp array
        vector<int>dp(n+1, -1); //in code n is changing
        return solveUsingMem(nums,n,dp);
    }
};