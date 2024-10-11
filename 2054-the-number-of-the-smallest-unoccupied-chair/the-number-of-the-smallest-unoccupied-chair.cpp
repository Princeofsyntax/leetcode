class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int, int>> arrivals;
        for (int i = 0; i < n; ++i) {
            arrivals.push_back({times[i][0], i});
        }

        sort(arrivals.begin(), arrivals.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingChairs;

        for (auto& arrival : arrivals) {
            int arrivalTime = arrival.first;
            int friendIdx = arrival.second;

            while (!leavingChairs.empty() && leavingChairs.top().first <= arrivalTime) {
                int freeChair = leavingChairs.top().second;
                leavingChairs.pop();
                availableChairs.push(freeChair);
            }

            int assignedChair = availableChairs.top();
            availableChairs.pop();

            if (friendIdx == targetFriend) {
                return assignedChair;
            }

            leavingChairs.push({times[friendIdx][1], assignedChair});
        }

        return -1;  
        }
};