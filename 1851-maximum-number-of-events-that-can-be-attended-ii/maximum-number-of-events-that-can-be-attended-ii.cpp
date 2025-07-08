class Solution {
public:
    vector<vector<int>>dp;

    int findNextIndex(int start, int end, vector<vector<int>>&events){
        int low = start, high = events.size();
        while(low<high){
            int mid = (low+high)>>1;
            if(events[mid][0] > end)high = mid;
            else low = mid+1;
        }
        return low;
    }

    int dfs(int index, int k, vector<vector<int>>&events){
        if(k == 0 || index >= events.size())return 0;
        if(dp[index][k] != -1)return dp[index][k];

        //skip
        int skip = dfs(index+1, k, events);
        //take
        int nextIndex = findNextIndex(index+1, events[index][1], events);
        int take = events[index][2] + dfs(nextIndex, k-1, events);

        return dp[index][k] = max(skip, take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        dp.assign(n,vector<int>(k+1,-1));
        return dfs(0, k, events);
    }
};