class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        //memo[i][j] will store the result for the subproblem from i to j
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n - 1, values, memo);
    }

private:
    int solve(int i, int j, vector<int>& values, vector<vector<int>>& memo) {
        //a polygon with 2 or fewer vertices has a score of 0
        if (j < i + 2) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int min_score = INT_MAX;

        //iterate through all possible intermediate vertices 'k' to form the triangle (i, k, j)
        for (int k = i + 1; k < j; ++k) {
            int current_score = values[i] * values[k] * values[j] 
                              + solve(i, k, values, memo) 
                              + solve(k, j, values, memo);
            min_score = min(min_score, current_score);
        }

        return memo[i][j] = min_score;
    }
};