class Solution {
public:
    static bool comparePoints(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] > b[1];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparePoints);

        int count = 0;
        int n = points.size();

        for (int j = 0; j < n; ++j) {
            int bob_y = points[j][1];
            int y_boundary = INT_MAX;

            for (int i = j - 1; i >= 0; --i) {
                int alice_y = points[i][1];
                if (alice_y >= bob_y) {
                    if (alice_y < y_boundary) {
                        count++;
                    }
                    y_boundary = min(y_boundary, alice_y);
                }
            }
        }
        return count;
    }
};