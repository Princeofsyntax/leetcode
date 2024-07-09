class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       int n = customers.size();

        if(n == 0) return 0;

        long long prevWait = 0;
        long long currWait = 0;
        long long time = 0;  // Initially set to 0
        long long wait = 0;

        for(int i = 0; i < n; ++i) {
            if(time < customers[i][0]) {
                time = customers[i][0]; // Update the time to customer's arrival time if it's greater
            }

            // Calculate the current waiting time
            prevWait = time - customers[i][0];
            currWait = customers[i][1];
            wait += prevWait + currWait;

            // cout << "The wait at " << i << "th index is " << wait << endl;
            time += currWait;
            // cout << "The time of taking charge is " << time << endl;
        }
        
        double avg1 = static_cast<double>(wait) / n;
        return avg1;
    }
};