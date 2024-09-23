class Solution {
public:
    int solve(int idx, int n,string &s, unordered_set<string>&dict, vector<int>&dp){
        if(idx >= n) return 0;
        int minExtra = n;
        string curr = "";
        if(dp[idx]!= -1) return dp[idx];

        for(int i = idx; i < n; i++){
            curr.push_back(s[i]);
            int currExtra = (dict.find(curr) == dict.end())? curr.size() : 0;
            int nextExtra = solve(i+1,n,s,dict,dp);
            int totalExtra = currExtra + nextExtra;
            minExtra = min(minExtra, totalExtra);
        }
        return dp[idx] = minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0,n,s,dict,dp);
    }
};