class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxVal = n*n;
        unordered_map<int,int>mp;
        for(int i = 1; i <= maxVal; i++){
            mp[i] = 0;
        }

        for(const auto&row : grid){
            for(const auto&val : row){
                mp[val]++;
            }
        }

        vector<int>ans(2);

        for(const auto&pair : mp){
            if(pair.second == 2){
                ans[0] = pair.first;
            }
            if(pair.second == 0){
                ans[1] = pair.first;
            }
        }
        return ans;
    }
};