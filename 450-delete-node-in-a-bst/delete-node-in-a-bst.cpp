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
    int maxvalue(TreeNode *root)
{
    TreeNode *temp = root;
    if (!temp)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
    if (!root)
    {
        return NULL;
    }

    if (root->val == key)
    {
        // isi ko delete krna hai -->4 cases
        if (root->left == NULL && root->right == NULL)
        {
            // leaf node
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            TreeNode *child = root->right;
            delete root;
            return child;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            TreeNode *child = root->left;
            delete root;
            return child;
        }
        else
        {
            // both child present
            // find inorder predecessor from left sub tree and replace it with the node to be deleted
            int inorderPre = maxvalue(root->left);
            root->val = inorderPre;
            // delete inorder predecssor from left subtree
            root->left = deleteNode(root->left, inorderPre);
            return root;
        }
    }
    else if (key > root->val)
    {
        // right jana chahiye
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->val)
    {
        // left jana chahiye
        root->left = deleteNode(root->left, key);
    }
    return root;
    }
};