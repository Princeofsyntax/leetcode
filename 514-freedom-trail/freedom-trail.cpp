class Solution {
public:
    
   int findRotateSteps(string ring, string key) {
    if (ring.empty() || key.empty()) return 0; // If ring or key is empty, no steps needed

    int ringSize = ring.size();
    int keySize = key.size();

    // Initialize map to store the positions of each character in the ring
    map<char, vector<int>> charPositions;
    for (int i = 0; i < ringSize; ++i) {
        charPositions[ring[i]].push_back(i);
    }

    // Initialize memoization table to store the minimum steps to reach each position for each character in the ring
    vector<vector<int>> dp(keySize, vector<int>(ringSize, INT_MAX));

    // Base case: for the first character in the key, calculate the steps needed to reach each position in the ring
    for (int pos : charPositions[key[0]]) {
        dp[0][pos] = min(pos, ringSize - pos) + 1; // Pressing the button
    }

    // Dynamic programming to calculate minimum steps for each character in the key
    for (int i = 1; i < keySize; ++i) {
        for (int curPos : charPositions[key[i]]) {
            for (int prevPos : charPositions[key[i - 1]]) {
                int steps = min(abs(curPos - prevPos), ringSize - abs(curPos - prevPos));
                dp[i][curPos] = min(dp[i][curPos], dp[i - 1][prevPos] + steps + 1); // 1 for pressing the button
            }
        }
    }

    // Find the minimum steps to reach the last character in the key
    int minSteps = INT_MAX;
    for (int steps : dp[keySize - 1]) {
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}
};