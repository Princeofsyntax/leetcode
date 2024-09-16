class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(const auto& time : timePoints){
            int hours = stoi(time.substr(0,2));
            int minute = stoi(time.substr(3,2));
            int totalMin = hours*60 + minute;
            minutes.push_back(totalMin);
        }
        sort(minutes.begin(), minutes.end());
        int minimum = INT_MAX;
        int n = minutes.size();
        for(int i = 0; i < n-1; i++){
            minimum = min(minimum, minutes[i+1]-minutes[i]);
        }
        //last check
        minimum = min(minimum, (minutes[0]+1440) - minutes[n-1]);

        return minimum;
    }
};