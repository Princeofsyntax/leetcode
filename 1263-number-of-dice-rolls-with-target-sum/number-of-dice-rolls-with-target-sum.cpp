class Solution {
public:
    int mod = 1000000007;

    int solveUsingSpaceOpt(int n, int k, int target)
    {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        // base case
        prev[0] = 1;

        // move opposite to top down approach 0 to n and 0 to target
        for (int index = 1; index <= n; index++)
        {
            for (int t = 1; t <= target; t++)
            {
                long long int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    long long int recAns = 0;
                    if (t - i >= 0)
                        recAns = prev[t - i];
                    ans = (ans % mod + recAns % mod) % mod;
                }
                curr[t] = ans;
            }
            // shifting
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        return solveUsingSpaceOpt(n,k,target);
    }
};