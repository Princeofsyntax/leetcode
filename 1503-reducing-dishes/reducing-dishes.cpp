class Solution {
public:
    int solve(vector<int> &sat)
    {
        // create dp
        vector<vector<int>> dp(sat.size() + 1, vector<int>(sat.size() + 2, 0));
        for (int i = sat.size() - 1; i >= 0; i--)
        {
            for (int j = sat.size(); j >= 1; j--)
            {
                int includeLikeTimeCoeff = j * sat[i] + dp[i + 1][j + 1];
                int excludeLikeTimeCoeff = dp[i + 1][j];
                // store and return
                dp[i][j] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
            }
        }
        return dp[0][1];
    }

    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction);
    }
};