class Solution {
public:
    int tribonacciHelper(int n, vector<int>&dp){
        //base case
        if(n == 0) return 0;
        if(n ==1 || n == 2) return 1;
        //check in dp
        if(dp[n] != -1) return dp[n];

        dp[n] = tribonacciHelper(n-1, dp) + tribonacciHelper(n-2, dp) + tribonacciHelper(n-3, dp);
        return dp[n];
    }

    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tribonacciHelper(n, dp);
    }
};