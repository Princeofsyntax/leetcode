class Solution {
public:
    // Trie 
    struct TrieNode {
        TrieNode* children[10]; 
        bool isEnd; 
        TrieNode() {
            for (int i = 0; i < 10; ++i) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };
    void insert(TrieNode* root, const string& num) {
    TrieNode* node = root;
    for (char c : num) {
        int index = c - '0'; 
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEnd = true;
   }

   int findLongestPrefix(TrieNode* root, const string& num) {
    TrieNode* node = root;
    int length = 0;
    for (char c : num) {
        int index = c - '0'; 
        if (node->children[index]) {
            length++;
            node = node->children[index];
        } else {
            break; 
        }
      }
    return length;
    }


    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for (int num : arr1) {
                insert(root, to_string(num));
            }
        int maxLength = 0;
        for (int num : arr2) {
            maxLength = max(maxLength, findLongestPrefix(root, to_string(num)));
        }
        return maxLength;
    }
};