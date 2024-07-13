class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> result;
        vector<pair<int, int>> robots; // pair<position, index>
        
        // Populate robots with their positions and original indices
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], i});
        }

        // Sort robots based on their positions
        sort(robots.begin(), robots.end());

        stack<int> stack; // to store indices of robots moving to the right

        for (const auto& robot : robots) {
            int pos = robot.first;
            int idx = robot.second;
            char dir = directions[idx];

            if (dir == 'R') {
                // Push the index of the robot moving to the right
                stack.push(idx);
            } else {
                // Handle collisions for robots moving to the left
                while (!stack.empty() && healths[idx] > 0) {
                    int rightIdx = stack.top();
                    if (healths[rightIdx] == healths[idx]) {
                        // Both robots have the same health, both are destroyed
                        healths[rightIdx] = 0;
                        healths[idx] = 0;
                        stack.pop();
                    } else if (healths[rightIdx] > healths[idx]) {
                        // Right moving robot survives, left moving robot is destroyed
                        healths[rightIdx]--;
                        healths[idx] = 0;
                    } else {
                        // Left moving robot survives, right moving robot is destroyed
                        healths[idx]--;
                        healths[rightIdx] = 0;
                        stack.pop();
                    }
                }
            }
        }

        // Collect the healths of surviving robots in the original order
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};