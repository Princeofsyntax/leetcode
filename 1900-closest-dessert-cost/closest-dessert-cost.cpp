class Solution {
public:
    int ans, diff;
    void dfs(vector<int> &T, int i, int sum, int target) {
        int d = abs(sum - target);
        if (d > diff && sum > ans) return;
        if (d < diff || (d == diff && sum < ans)) {
            ans = sum;
            diff = d;
        }
        if (i == T.size()) return;
        for (int j = 0; j <= 2; ++j) dfs(T, i + 1, sum + j * T[i], target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        ans = baseCosts[0];
        diff = abs(target - ans);
        for (int b : baseCosts) dfs(toppingCosts, 0, b, target);
        return ans;
    }
};