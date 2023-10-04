class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // first convert in minutes
    vector<int> minutes;
    for (int i = 0; i < timePoints.size(); i++)
    {
        string curr = timePoints[i];
        // hours are in string format
        int hours = stoi(curr.substr(0, 2));
        // stoi converts string to integer
        int minute = stoi(curr.substr(3, 2));
        int totalMinutes = hours * 60 + minute;
        minutes.push_back(totalMinutes);
    }

    // sort to deccrease comparison --> so that we have to check adjacent only
    sort(minutes.begin(), minutes.end());

    // find difference
    int mini = INT_MAX;
    int n = minutes.size();

    for (int i = 0; i < n - 1; i++) // n-1 is taken as we are already using i+1
    {
        int diff = minutes[i + 1] - minutes[i];
        mini = min(mini, diff);
    }

    // something missing
    int lastDiff = (minutes[0] + 1440) - minutes[n - 1];
    mini = min(mini, lastDiff);

    return mini;
    }
};