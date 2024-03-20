class Solution {
public:
    int maxLen = 1; // as single character is also palindrome
    int start = 0;

    bool solve(string& s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return true;
        }
        // check
        if (dp[i][j] != -1)
            return dp[i][j];

        bool flag = false;
        if (s[i] == s[j])
        {
            flag = solve(s, i + 1, j - 1, dp);
        }
        if (flag)
        {
            int currLen = j - i + 1;
            if (currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        // store and return
        return dp[i][j] = flag;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        // create dp
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                bool t = solve(s, i, j, dp);
            }
        }
        return s.substr(start, maxLen);
    }
};