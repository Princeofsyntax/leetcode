/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int calculateMinSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        int swaps = 0;
        // Detect cycles
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i) continue; 
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second; 
                ++cycleSize;
            }
            if (cycleSize > 1) swaps += (cycleSize - 1);
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
           totalSwaps += calculateMinSwaps(levelValues);
        }
        return totalSwaps;
    }
};