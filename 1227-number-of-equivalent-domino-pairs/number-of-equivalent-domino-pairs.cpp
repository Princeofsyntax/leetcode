class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int>mp;
        int ans = 0;
        for (auto& d : dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            ans += mp[key];  
            mp[key]++;
        }
        return ans;
    }
};