class LFUCache {
public:
     class Node {
    public:
        int key;
        int value;
        int freq;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
            freq = 1;
        }
    };

    int capacity; 
    int minFreq;   
    unordered_map<int, Node*> keyNode; 
    unordered_map<int, list<Node*>> freqList;  
    unordered_map<int, list<Node*>::iterator> nodeIter; 

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreqList(Node* node) {
        int freq = node->freq;
        freqList[freq].erase(nodeIter[node->key]);

       if (freqList[freq].empty() && minFreq == freq) {
            minFreq++;
        }

        node->freq++;
        freqList[node->freq].push_front(node);  
        nodeIter[node->key] = freqList[node->freq].begin();  
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1; 
        Node* node = keyNode[key];
        updateFreqList(node); 
        return node->value;   
    }

    void put(int key, int value) {
        if (capacity == 0) return; 
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;  
            updateFreqList(node); 
        } else {
             if (keyNode.size() == capacity) {
                Node* nodeToEvict = freqList[minFreq].back();  
                keyNode.erase(nodeToEvict->key);  
                nodeIter.erase(nodeToEvict->key);  
                freqList[minFreq].pop_back(); 
                delete nodeToEvict;  
            }

            Node* newNode = new Node(key, value);
            keyNode[key] = newNode;
            freqList[1].push_front(newNode); 
            nodeIter[key] = freqList[1].begin(); 
            minFreq = 1;  
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
