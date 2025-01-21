class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long>prefixTop(n+1,0), prefixBottom(n+1,0);
        for(int i = 0; i < n; i++){
            prefixTop[i+1] = prefixTop[i] + grid[0][i];
            prefixBottom[i+1] = prefixBottom[i] + grid[1][i];
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            long long secondTopPoints = prefixTop[n] - prefixTop[i+1];//if first robot moves down
            long long secondBottomPoints = prefixBottom[i]; //if first robot goes on right
            long long secondPoints = max(secondTopPoints, secondBottomPoints);
            ans = min(ans, secondPoints); //as first robot will maximise its point
        }
        return ans;
    }
};