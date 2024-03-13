class Solution {
public:
    //overlapping subproblem(dp)

    int solveMem(vector<int>& coins, int amount, vector<int>&dp){
         //base case
        if(amount == 0){
            return 0; //to create 0 amount we need 0 coins
        }
        if(amount < 0){
            //return that value which do not impact the result
            return INT_MAX;
        }
        //3.check if answer already exists
        if(dp[amount] != -1 ){
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = solveMem(coins, amount-coins[i], dp);
            if(ans != INT_MAX){
               //valid answer
               mini = min(1+ans,mini);//1 is for the coin which is being used
            }
        }

        //2.store the answer
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        //1.create dp array
        vector<int>dp(amount+1, -1);
        int ans = solveMem(coins,amount,dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};