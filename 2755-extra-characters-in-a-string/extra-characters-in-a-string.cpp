class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;

            for (int j = 0; j < i; ++j) {
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
        }
};