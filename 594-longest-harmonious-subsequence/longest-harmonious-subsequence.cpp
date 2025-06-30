class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(const auto &num : nums){
            mp[num]++;
        }
        int longest = 0;
        for(const auto& pair : mp){
            if(mp.find(pair.first + 1) != mp.end()){
                longest = max(longest, pair.second + mp[pair.first+1]);
            }
        }
        return longest;
    }
};