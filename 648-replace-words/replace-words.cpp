class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) : data(ch), isTerminal(false)
        {
            for(int i = 0; i < 26; ++i){
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
        int index = word[i] - 'a';
        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }

    bool searchUtil(TrieNode* root, string &word, int &i){
        if(root->isTerminal){
            return true;
        }
        if(i >= word.size()){
            return root->isTerminal;
        }
        int index = word[i++] - 'a';

        if(root->children[index]){
            return searchUtil(root->children[index], word, i);
        }
        return false;
    }

    bool startWithUtil(TrieNode* root, string &word, int i){
        if(i >= word.size()){
            return true;
        }
        int index = word[i] - 'a';
        if(root->children[index]){
            return startWithUtil(root->children[index], word, i+1);
        }
        return false;
    }
public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(root,word,0);
    }
    
    int search(string word) {
        int i = 0;
        bool gotIt = searchUtil(root,word,i);
        return gotIt ? i : -1 ; //if gotIt is true than return i else return -1
    }
    
    bool startsWith(string prefix) {
        return startWithUtil(root, prefix, 0);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        //use tries
        string ans;
        Trie trie;
        //insert dictionary into trie
        for(auto root : dictionary){
            trie.insert(root);
        }
        //pick each word and find in trie whether root is available or not
        int start = 0; int end = 0;
        while(end < sentence.size()){
          if(sentence[end] == ' ' || end == sentence.size()-1){
               //second case in if is when sentence is finished
               int len = end == sentence.size()-1 ? sentence.size() : end-start;
               string word = sentence.substr(start,len);
               int trieMatchIndex = trie.search(word);
               ans += trieMatchIndex != -1 ? word.substr(0,trieMatchIndex) : word ;
               if(sentence[end] == ' '){
                ans += " ";
               }
               start = end+1;
          }
          ++end;
        }
        return ans;
    }
};