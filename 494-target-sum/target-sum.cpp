class Solution {
public:
    int helper(int i, vector<int>&arr, int sum, vector<vector<int>>& dp) {
        if (i == 0) {
            if(arr[0] == 0 && sum == 0) return 2; 
            if(sum == 0 || sum == arr[0])return 1;
            return 0;
        } 
        
        
        if (dp[i][sum] != -1) return dp[i][sum];
        
        int notPick = helper(i - 1, arr, sum, dp);
        
        int pick = 0;
        if (arr[i] <= sum) {
            pick = helper(i - 1, arr, sum - arr[i], dp);
        }
        
        return dp[i][sum] = (pick + notPick);
    }
    

    int findTargetSumWays(vector<int>& arr, int d) {
        // basically we have to divide the nums into two parts such that there difference is target
         // Target is to find a sum = (totalSum - d)/2 
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum - d < 0 || (totalSum - d)%2 ) return false; // As we need even
        int sum = (totalSum - d)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(n-1, arr, sum, dp);
    }
};