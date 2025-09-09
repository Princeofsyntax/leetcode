class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, 0);  //dp[i] = people who learn the secret on day i
        dp[1] = 1; //day 1 person knows
        int mod = 1e9 + 7;
        for (int day = 2; day <= n; day++) {
            //people who can share the secret today:
            for (int j = day - forget + 1; j <= day - delay; j++) {
                if (j >= 1) {
                    dp[day] = (dp[day] + dp[j]) % mod;
                }
            }
        }
        //sum people learned within last forget days
        int ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) {
                ans = (ans + dp[day]) % mod;
            }
        }
        return ans;
    }
};
