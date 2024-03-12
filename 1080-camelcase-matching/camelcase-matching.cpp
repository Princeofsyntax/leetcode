class TrieNode{
    public:
        char data;
        TrieNode* children[58];
        bool isTerminal;

        TrieNode(char ch) : data(ch), isTerminal(false)
        {
            for(int i = 0; i < 58; ++i){
                children[i] = 0;
            }
        }
};
class Trie 
{
    TrieNode* root;

    void insertUtil(TrieNode* root, string &word, int i){
        if(i >= word.size()){
            root->isTerminal = true;
            return;
        }
        int index = word[i] - 'A'; //we have to iterate over trie only in case of capital letter 
        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }

    bool searchUtil(TrieNode* root, string &word, int i){
        if(i >= word.size()){
            return root->isTerminal;
        }
        int index = word[i] - 'A';

        if(root->children[index]){
            return searchUtil(root->children[index], word, i+1);
        }
        else if(islower(word[i])){
            //small alphabet is present --> move to next character in word
            return searchUtil(root, word, i+1); //remaining at same node ; moves to next character in word
        }
        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string &word) {
        insertUtil(root,word,0);
    }
    
    bool search(string &word) {
        return searchUtil(root,word,0);
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);
        for(auto query : queries){
           ans.push_back(trie.search(query));
        }
        return ans;
    }
};