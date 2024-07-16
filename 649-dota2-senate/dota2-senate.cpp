class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();

        // Populate the queues with the indices of the senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Process the queues
        while (!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();

            // The senator with the smaller index bans the other
            if (r_index < d_index) {
                radiant.push(r_index + n); // Push back to queue with increased index
            } else {
                dire.push(d_index + n); // Push back to queue with increased index
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};