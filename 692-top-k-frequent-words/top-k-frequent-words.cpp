class comp{
    public:
        bool operator()(const pair<int,string>&a, const pair<int,string>&b){
            return a.first == b.first ? a < b : a.first > b.first ;
            //if frequency is equal then consider that pair which is lexically smaller ELSE use that whose frequency is greater
        }
};
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int freq; //to count how many time the string came

        TrieNode(char ch) : data(ch), isTerminal(false)
        {
            for(int i = 0; i < 26; ++i){
                children[i] = 0;
                freq = 0;
            }
        }
};
class Trie 
{
    TrieNode* root;

    void insertUtil(TrieNode* root, string &word, int i){
        if(i >= word.size()){
            root->isTerminal = true;
            ++root->freq; //frequency
            return;
        }
        int index = word[i] - 'a';
        if(!root->children[index]){
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index],word,i+1);
    }
 
    void traverseUtil(TrieNode* root, string &s, priority_queue<pair<int,string>, vector<pair<int,string>>, comp>&pq, int &k){
       if(!root){
            return;
       }
       if(root->isTerminal){
        //stores top k frequent words
         if(pq.size() < k){
            pq.push({root->freq, s});
         }
         else if(pq.size() == k && root->freq > pq.top().first){
            pq.pop();
            pq.push({root->freq, s});
         }
       }
       for(int i = 0; i < 26; i++){
          if(root->children[i]){
            s.push_back(i+'a');
            traverseUtil(root->children[i],s,pq,k);
            //backtracking
            s.pop_back();
          }
       }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(root,word,0);
    }

    void traverse(priority_queue<pair<int,string>, vector<pair<int,string>>, comp>&pq, int &k){
       string s;
       traverseUtil(root,s,pq,k);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //can be solved using hashMAps --> let us try with tries
        //leetcode 208 trie code modified
        Trie trie;
        vector<string>ans;
        for(auto word : words){
            trie.insert(word);
        }
        //for k frequent words we need priority queue 
        priority_queue<pair<int,string>, vector<pair<int,string>>, comp>pq; // { freq, word} //minHeap
        trie.traverse(pq,k);

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};