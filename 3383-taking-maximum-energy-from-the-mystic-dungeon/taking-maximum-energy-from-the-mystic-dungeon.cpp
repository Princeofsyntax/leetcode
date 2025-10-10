class Solution {
public:
    vector<int>dp;

    int helper(vector<int>&energy, int &n, int &k, int i){
        if(i >= n) return 0;
        if(dp[i] != INT_MIN) return dp[i];
        return dp[i] = energy[i] + helper(energy, n, k, i+k);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        dp.resize(n,INT_MIN);
        for(int i = 0; i < n; i++){
            int curr = energy[i] + helper(energy, n, k, i+k);
            ans = max(ans,curr);
        }
        return ans;
    }
};