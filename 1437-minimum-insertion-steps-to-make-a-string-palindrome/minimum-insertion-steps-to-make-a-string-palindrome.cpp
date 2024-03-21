class Solution {
public:
      //refer leetcode 516 code
      int solveUsingTabSO(string a, string b)
    {
        // vector<vector<int>>dp (a.length() + 10, vector<int>(b.length()+10,0));
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                    ans = 1 + next[j + 1];
                else
                    ans = 0 + max(curr[j + 1], next[j]);

                curr[j] = ans;
            }
            // shift
            next = curr;
        }
        return next[0];
    }

    int longestPalindromeSubseq(string &s)
    {
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;
        return solveUsingTabSO(first, second);
    }

    int minInsertions(string s)
    {
        // length of subsequence which is already palindrome
        int LPS_len = longestPalindromeSubseq(s);
        int insertionsToDo = s.size() - LPS_len;
        return insertionsToDo;
    }

};