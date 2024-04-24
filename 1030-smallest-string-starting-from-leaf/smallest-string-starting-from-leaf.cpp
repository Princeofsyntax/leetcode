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
    void dfs(TreeNode* root, string&& path, string& ans) {
        //base case
        if (root == nullptr)
            return; 

        path.push_back(root->val + 'a'); //Firstly converting root value (integer) to characer and then appending to path

        if (root->left == nullptr && root->right == nullptr) { 
            reverse(path.begin(), path.end()); // Reverse the path to get leaf to root order
            if (ans == "" || ans > path) 
                ans = path; // Update the result with the current path
            reverse(path.begin(), path.end()); // Roll back the path to its original order
        }

        // Recursive calls for left and right children, moving the path string to avoid copying
        dfs(root->left, move(path), ans);
        dfs(root->right, move(path), ans);
        
        path.pop_back(); // Backtrack by removing the last character from the path
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans; 
        dfs(root, "", ans); // Call depth-first search (DFS) function with empty path and reference to result
        return ans; 
    }
};