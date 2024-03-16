class Solution {
public:
    int solveUsingTabulation(vector<int> &arr, map<pair<int, int>, int> &maxi)
    {
        int n = arr.size();
        // create dp
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // move opposite to top down dp
        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = 0; right <= n - 1; right++)
            {
                if (left >= right)
                {
                    continue;
                }
                else
                {
                    // valid range
                    int ans = INT_MAX;
                    for (int i = left; i < right; i++)
                    {
                        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                    }
                    // 2.store ans in dp
                    dp[left][right] = ans;
                }
            }
        }
        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi; // key as range and value as max. element in that range
        // pre-computation
        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size();
        int ans = solveUsingTabulation(arr, maxi);
        return ans;
    }
};