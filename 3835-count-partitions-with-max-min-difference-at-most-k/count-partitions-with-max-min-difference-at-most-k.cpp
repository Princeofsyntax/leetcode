class Solution {
public:
    static const long long MOD = 1000000007LL;

    int countPartitions(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<long long> dp(n+1, 0), pref(n+1, 0); // dp[0..n], pref[i] = sum_{0..i} dp
        dp[0] = 1;
        pref[0] = 1;

        deque<int> dqMin, dqMax; // store indices, dqMin -> increasing values, dqMax -> decreasing values
        int l = 1; // window start (1-indexed for convenience with dp)
        for (int r = 1; r <= n; ++r) {
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[r-1]) dqMin.pop_back();
            dqMin.push_back(r-1);
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[r-1]) dqMax.pop_back();
            dqMax.push_back(r-1);

            // move l forward until window [l..r] satisfies max-min <= k
            while (l <= r) {
                int curMin = nums[dqMin.front()];
                int curMax = nums[dqMax.front()];
                if ((long long)curMax - (long long)curMin <= k) break;
                if (!dqMin.empty() && dqMin.front() == l-1) dqMin.pop_front();
                if (!dqMax.empty() && dqMax.front() == l-1) dqMax.pop_front();
                ++l;
            }

            long long leftPref = (l-2 >= 0) ? pref[l-2] : 0; // pref index might be -1 -> treat as 0
            long long val = (pref[r-1] - leftPref) % MOD;
            if (val < 0) val += MOD;
            dp[r] = val;
            pref[r] = (pref[r-1] + dp[r]) % MOD;
        }

        return (int)dp[n];
    }
};
