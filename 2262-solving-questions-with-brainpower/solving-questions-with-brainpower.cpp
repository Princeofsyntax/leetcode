class Solution {
public:
    vector<long long> dp;
    
    long long helper(vector<vector<int>>& questions, int i) {
        int n = questions.size();
        if (i >= n) return 0;  
        if (dp[i] != -1) return dp[i];  
        long long take = questions[i][0] + helper(questions, i + questions[i][1] + 1);
        long long notTake = helper(questions, i + 1);
        return dp[i] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);  //initialize DP table with -1
        return helper(questions, 0);
    }
};
