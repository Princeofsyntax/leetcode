class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleLength = 2 * (n - 1);
        time %= cycleLength;

        // If the time is less than n, the direction is forward
        if (time < n) {
            return time + 1;
        } else {
            // If the time is greater or equal to n, the direction is backward
            return 2 * n - time - 1;
        }
    }
};