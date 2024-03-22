class Solution {
public:
    int solve(vector<int> &piles)
    {
        // create dp 3D
        vector<vector<vector<int>>> dp(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, 0)));

        for (int i = piles.size() - 1; i >= 0; i--)
        {
            for (int m = piles.size(); m >= 1; m--)
            {
                for (int alice = 0; alice <= 1; alice++)
                {
                    int ans = alice ? INT_MIN : INT_MAX; // if alice turn --> maximise ; if bob turn --> minimise
                    int total = 0;
                    for (int x = 1; x <= 2 * m; x++)
                    {
                        if ((i + x - 1) >= piles.size())
                            break;
                        total += piles[i + x - 1];
                        if (alice)
                        {
                            ans = max(ans, total + dp[i + x][max(x, m)][!alice]);
                        }
                        else
                        {
                            ans = min(ans, dp[i + x][max(x, m)][!alice]);
                        }
                        // store and return
                        dp[i][m][alice] = ans;
                    }
                }
            }
        }
        return dp[0][1][1];
    }

    int stoneGameII(vector<int> &piles)
    {
        return solve(piles);
    }
};