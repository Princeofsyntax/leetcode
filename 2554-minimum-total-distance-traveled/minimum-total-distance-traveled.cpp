class Solution {
public:
    long long dfs(int r, int f, vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>>& memo) {
        // if all robots are repaired, return 0 distance
        if (r == robot.size()) return 0;
        //if no factories left, return an invalid large distance
        if (f == factory.size()) return LLONG_MAX;
        
        if (memo[r][f] != -1) return memo[r][f];

        long long minDistance = LLONG_MAX;

        minDistance = dfs(r, f + 1, robot, factory, memo);

        long long distance = 0;
        for (int i = 0; i < factory[f][1] && r + i < robot.size(); ++i) {
            distance += abs(robot[r + i] - factory[f][0]);
            long long nextDistance = dfs(r + i + 1, f + 1, robot, factory, memo);
            if (nextDistance != LLONG_MAX) {
                minDistance = min(minDistance, distance + nextDistance);
            }
        }

        return memo[r][f] = minDistance;  
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> memo(n, vector<long long>(m, -1));

        // Start recursion with first robot and first factory
        return dfs(0, 0, robot, factory, memo);
    }
};