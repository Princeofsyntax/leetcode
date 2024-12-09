class Solution {
public:
    bool helper(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
    if (i < 0 && j < 0) return true; // Both strings are exhausted
    if (i < 0 && j >= 0) return false; // Pattern exhausted but text remains
    if (j < 0 && i >= 0) { // Text exhausted but pattern remains
        for (int x = 0; x <= i; x++) if (p[x] != '*') return false; // Remaining pattern must be all '*'
        return true;
    }
    if (dp[i][j] != -1) return dp[i][j];
    // Matching conditions
    if (p[i] == s[j] || p[i] == '?') 
        return dp[i][j] = helper(i - 1, j - 1, p, s, dp);

    if (p[i] == '*') 
        return dp[i][j] = helper(i - 1, j, p, s, dp) || helper(i, j - 1, p, s, dp); // '*' matches empty or any character
    return dp[i][j] = false;
}

bool isMatch(string s, string p) {
    int m = p.size();
    int n = s.size();
    vector<vector<int>> dp(m, vector<int>(n, -1)); 
    return helper(m - 1, n - 1, p, s, dp);
    }
};