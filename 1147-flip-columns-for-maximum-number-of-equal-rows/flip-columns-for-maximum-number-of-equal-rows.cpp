class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int ans = 0;
       unordered_map<string,int>mp;
       for(auto row : matrix){
            string original, flipped;
            for(auto num : row){
                original += (num + '0');
                flipped += ((1-num) + '0');
            }
            mp[original]++;
            mp[flipped]++;
            ans = max(ans, max(mp[original], mp[flipped]));
       }
       return ans;
    }
};