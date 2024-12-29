class Solution {
public:
    int MOD = 1e9 + 7;
    long long dfs(int targetIndex, int wordIndex, const string& target, const vector<vector<int>>& freq, vector<vector<int>>& dp){
        if (targetIndex == target.size()) return 1; // Successfully formed the target
        if (wordIndex == freq[0].size()) return 0; // Ran out of columns

        if (dp[targetIndex][wordIndex] != -1) return dp[targetIndex][wordIndex];

        long long ways = dfs(targetIndex, wordIndex + 1, target, freq, dp); // Skip this column

        if (freq[target[targetIndex] - 'a'][wordIndex] > 0) {
            ways += dfs(targetIndex + 1, wordIndex + 1, target, freq, dp) * freq[target[targetIndex] - 'a'][wordIndex];
            ways %= MOD;
        }

        return dp[targetIndex][wordIndex] = ways;
    }


    int numWays(vector<string>& words, string target) {
        int m = target.size(), n = words[0].size();
        // Frequency count of characters at each column
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return dfs(0, 0, target, freq, dp);
    }
};