class Solution {
public:

    // Tries
    struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    };

    class Trie{
        public:
            Node* root;
            Trie(){
                root = new Node();
            }
        public:
            void insert(int num){
                Node* node = root;
                for(int i = 31; i >= 0; i--){
                    int bit = (num >> i) & 1;
                    if(!node->containsKey(bit)){
                        node->put(bit, new Node());
                    }
                    node = node->get(bit);
                }
            }

            int getMax(int num){
                Node* node = root;
                int maxNum = 0;
                for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(1-bit)){
                    // to check if opposite bit is present to maximise the XOR
                    maxNum = maxNum | (1 << i);
                    node = node->get(1-bit);
                }
                else{
                    node = node->get(bit);
                }
                }
                return maxNum;
            }
    };

    int findMaximumXOR(vector<int>& A) {
        Trie trie;
        for(auto& it : A){
           trie.insert(it);
        }
        int maxi = 0;
        for(auto& it : A){
           maxi = max(maxi, trie.getMax(it));
         }
        return maxi;
    }
};