class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky = -1;
        unordered_map<int,int>mp;
        for(const auto& a : arr) mp[a]++;
        
        for(auto pair : mp) if(pair.first == pair.second) lucky = max(lucky, pair.first);
        
        return lucky;
    }
};