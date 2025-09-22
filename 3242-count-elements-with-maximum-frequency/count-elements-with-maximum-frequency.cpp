class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(const auto& num : nums) mp[num]++;
        int maxi = 1;
        for(const auto& m : mp) maxi = max(maxi, m.second);
        int ans = 0;
        for(const auto& m : mp) if(m.second == maxi) ans+=maxi;
        return ans;
    }
};