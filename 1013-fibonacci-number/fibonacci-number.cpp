class Solution {
public:
    // int recSolve(int n){
    //     //base case
    //     if(n == 0 || n == 1){
    //         return n;
    //     }
    //     int ans = recSolve(n-1) + recSolve(n-2);
    //     return ans;
    // }

    int topDownSolve(int n, vector<int>&dp){
         //copy the recursive code aand change function name
          //base case
            if(n == 0 || n == 1){
                return n;
            }
            //step 3 - check if answer already exists
            if(dp[n] != -1){
                //answer exists
                return dp[n];
            }

            //step 2 - replace ans with dp[n]
            dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
            return dp[n];
        }

    int fib(int n) {
        // int ans = recSolve(n);
        // return ans;

        //step 1 - create dp array ( n to 0 --> n+1 elements)
        vector<int>dp(n+1, -1);
        int ans = topDownSolve(n, dp);
        return ans;
    }
};