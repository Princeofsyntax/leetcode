class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[r] = maximum sum with remainder r (0,1,2)
        vector<int> dp(3, INT_MIN);
        dp[0] = 0;   // sum = 0 gives remainder 0

        for (int x : nums) {
            // copy old dp to update new dp safely
            vector<int> newdp = dp;

            for (int r = 0; r < 3; r++) {
                if (dp[r] == INT_MIN) continue; // skip impossible states

                int newRemainder = (r + x) % 3;
                newdp[newRemainder] = max(newdp[newRemainder], dp[r] + x);
            }

            dp = newdp;  // update dp
        }

        return dp[0];
    }
};