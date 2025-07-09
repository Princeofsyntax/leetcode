class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>free;
        free.push_back(startTime[0]); //free time for first 

        for(int i = 1; i < n; i++) free.push_back(startTime[i]-endTime[i-1]); 

        free.push_back(eventTime - endTime[n-1]); //free time for last

        int freeSpace = 0;

        for(int i = 0; i <=k ; i++) freeSpace += free[i];

        int ans = freeSpace;

        for(int i = k+1; i < free.size();i++){
            freeSpace += free[i] - free[i-(k+1)]; //window sliding
            ans = max(ans, freeSpace);
        }
        return ans;
    }
};