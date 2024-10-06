/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode == nullptr) s.append("#,");
            else s.append(to_string(currNode->val) + ',');
            if(currNode != nullptr) {
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        // Remove the last comma
        s.pop_back();
        return s;
    }

    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") node->left = nullptr;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#") node->right = nullptr;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
