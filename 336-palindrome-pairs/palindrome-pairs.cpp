class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int stringNumber; //original words array index of that string

        TrieNode(char ch) : data(ch), stringNumber(-1)
        {
            for(int i = 0; i < 26; ++i){
                children[i] = 0;
            }
        }
};
class Trie 
{
    TrieNode* root;

    void insertUtil(TrieNode* root, string &word, int i, int &stringNumber){
        if(i >= word.size()){
            root->stringNumber = stringNumber;
            return;
        }
        int index = word[i] - 'a';
        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1, stringNumber);
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string &word, int &stringNumber) {
        insertUtil(root,word,0,stringNumber);
    }
    
    bool isPallindrome(string &s, int low, int high){
        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }
            low++,high--;
        }
        return true;
    }

    void searchcase2(TrieNode* root, vector<int>&myPallindrome, string s){
        if(root -> stringNumber != -1){
            if(isPallindrome(s,0,s.size()-1)){
               myPallindrome.push_back(root->stringNumber);
            }
        }
        for(int i = 0; i < 26; i++){
            if(root->children[i] != 0){
                 s.push_back(i+'a');
                 searchcase2(root->children[i], myPallindrome,s );
                 //backtracking
                 s.pop_back();
            }
        }
    }

    void search(string &word, vector<int>&myPallindrome) {
       TrieNode* curr = root;

       //case1: When a prefix of string word, exactly matches with a word in trie
       for(int i = 0; i < word.size(); i++){
         int index = word[i]-'a';
         if(curr->stringNumber != -1){
            //word matched
            //check if the left search-word forms pallindrome!!
            if(isPallindrome(word, i, word.size()-1)){
                myPallindrome.push_back(curr->stringNumber);
            }
         }

         if(curr->children[index]){
            curr = curr->children[index];
         }
         else{
            return; 
         }
       }
       //case2 : search-word is a prefix of a word in the trie
       //check remaining subtrees in the trie for the pallindrome
       searchcase2(curr, myPallindrome, "");
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //create Trie and insert words in reverse order
        //for each word --> search trie and check pallindrome possible
        vector<vector<int>>ans;
        Trie trie;

        //insert all words in reverse order and mark its stringNumber as index of words array
        for(int i = 0; i < words.size(); i++){
            auto reverseWord = words[i];
            reverse(reverseWord.begin(), reverseWord.end());
            trie.insert(reverseWord, i);
        }
        //find pallindromic pairs of each word
        for(int i = 0; i < words.size(); i++){
            vector<int>myPallindrome; //array stores pallindromic pairs of ith word

            trie.search(words[i], myPallindrome);

            for(auto it : myPallindrome){
              if(it != i){
                ans.push_back({i, it});
              }
            }
        }
        //T.C = O( n*k^2)  ; k is length of longest string
        return ans;
    }
};