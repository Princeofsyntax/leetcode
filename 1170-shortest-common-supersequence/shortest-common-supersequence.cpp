class Solution {
public:
    // string helper(string &str1, string &str2, vector<vector<string>>&dp, int i, int j){
    //     if(i == 0)return str2.substr(0,j);
    //     if(j == 0)return str1.substr(0,i);

    //     if(dp[i][j] != "") return dp[i][j];
    //     if (str1[i - 1] == str2[j - 1]) return dp[i][j] = helper(str1, str2, dp, i - 1, j - 1) + str1[i - 1];
    //     string option1 = helper(str1, str2,dp, i - 1, j) + str1[i-1];
    //     string option2 = helper(str1, str2,dp, i, j - 1) + str2[j-1];

    //     return dp[i][j] = (option1.size() < option2.size()) ? option1 : option2;
    // }

    string shortestCommonSupersequence(string str1, string str2) {
        // int m = str1.size();
        // int n = str2.size();
        // vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
        // return helper(str1, str2, dp, m, n);
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i = m, j = n;
        string result = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};