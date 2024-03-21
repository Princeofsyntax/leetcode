class Solution {
public:
     static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            // same width
            return a[1] > b[1]; // return whose height is greater(sorting on decreasing height)
        }
        return a[0] < b[0]; // increasing sort
    }

    int solveOptimal(vector<vector<int>> &arr)
    {
        // sorts envelopes in increasing order of width
        // and sort in decrreasing order when Wi = Wj (to ensure that all left side envelopes are russian doll )
        sort(arr.begin(), arr.end(), comp);

        // RUN LIS ON HEIGHT

        if (arr.size() == 0)
            return 0;
        vector<int> ans;

        ans.push_back(arr[0][1]);

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][1] > ans.back())
            {
                // include
                ans.push_back(arr[i][1]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin(); // provides the required index
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }

    int solve2(vector<vector<int>> &env, int prev, int i, vector<vector<int>> &dp)
    {
        if (i == env.size())
            return 0;
        // check
        if (dp[prev + 1][i] != -1)
            return dp[prev + 1][i];

        int include = INT_MIN;
        if (prev == -1 || env[prev][0] < env[i][0] && env[prev][1] < env[i][1])
        {
            include = 1 + solve2(env, i, i + 1, dp);
        }
        int exclude = 0 + solve2(env, prev, i + 1, dp);
        // store and return
        return dp[prev + 1][i] = max(include, exclude); // as prev was -1 at begining
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        return solveOptimal(envelopes);
        // create 2D dp
        vector<vector<int>> dp(envelopes.size() + 1, vector<int>(envelopes.size() + 1, -1));
        return solve2(envelopes, -1, 0, dp);
    }
};