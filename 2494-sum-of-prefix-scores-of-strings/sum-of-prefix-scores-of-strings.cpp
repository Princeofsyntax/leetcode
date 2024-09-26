class Solution {
public:
    // Trie Node structure
struct TrieNode {
    TrieNode* children[26];  // For 26 lowercase English letters
    int count;  // To store the count of words passing through this node

    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count += 1;  
        }
    }

    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int totalScore = 0;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            totalScore += node->count;  
        }
        return totalScore;
    }
};

    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
    
        for (const string& word : words) {
            trie.insert(word);
        }
        
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
        }
};