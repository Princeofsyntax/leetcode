class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if(n <= 1) return 0;
        int ans = 0;
        int curr = 0;
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[curr]){
                if(neededTime[i] >= neededTime[curr]){
                    ans += neededTime[curr];
                    curr = i;
                } 
                else{
                    ans += neededTime[i];
                }
                continue;
            }
            curr = i;
        }
        return ans;
    }
};