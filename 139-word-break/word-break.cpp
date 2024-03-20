class Solution {
public:
   bool check(vector<string> &wordDict, string &word)
    {
        for (auto i : wordDict)
        {
            if (word == i)
                return true;
        }
        return false;
    }

   bool solve(string &s, vector<string> &wordDict, vector<int> &dp)
    {
        for (int start = s.size() - 1; start >= 0; start--)
        {
            string word = "";
            bool flag = false;
            for (int i = start; i < s.size(); i++)
            {
                word += s[i];
                if (check(wordDict, word))
                {
                    flag = flag || dp[i + 1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        // create dp
        vector<int> dp(s.size() + 1, true);
        return solve(s, wordDict, dp);
    }
};