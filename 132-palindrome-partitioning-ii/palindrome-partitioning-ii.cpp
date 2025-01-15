class Solution {
public:
    bool isPalindrome(string& k){
        int i = 0;
        int j = k.size()-1;
        while(i < j) if(k[i++] != k[j--])return false;
        return true;
    }

    int f(int i, string& s, int n, vector<int>&dp){
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];
        int minCuts = INT_MAX;
        string temp = "";
        for(int j = i; j < n; j++){
            temp += s[j];
            if(isPalindrome(temp)){
                int cuts = 1 + f(j+1, s, n, dp);
                minCuts = min(minCuts, cuts);
            }
        }
        return dp[i] = minCuts;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0, s, n, dp) - 1;  //To avoid partition at the end
    }
};