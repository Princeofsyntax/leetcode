class Solution {
public:
    void helper(int k, int n, int start, vector<int>& current, vector<vector<int>>& ans) {
        // Base cases
        if (n == 0 && current.size() == k) {
            ans.push_back(current);
            return;
        }
        if (n < 0 || current.size() >= k) {
            return;
        }

        // Try each number from 'start' to 9
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            helper(k, n - i, i + 1, current, ans);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        helper(k, n, 1, current, ans);
        return ans;
    }
};