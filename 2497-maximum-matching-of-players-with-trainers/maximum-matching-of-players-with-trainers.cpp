class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        int m = players.size();
        int n = trainers.size();
        if(m == 0 || n == 0) return 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        while(i < m && j < n){
            if(players[i] <= trainers[j]){
                ans++;
                i++,j++;
            }
            else j++;
        }
        return ans;
    }
};