class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node(int c) : count(c) {}
    };
    
    list<Node> dll; 
    unordered_map<string, list<Node>::iterator> keyCountMap;
    unordered_map<int, list<Node>::iterator> countNodeMap;  

public:
    AllOne() {
    }
    
    void inc(string key) {
        if (keyCountMap.find(key) == keyCountMap.end()) {
            if (dll.empty() || dll.front().count != 1) {
                dll.push_front(Node(1));
                countNodeMap[1] = dll.begin();
            }
            dll.front().keys.insert(key);
            keyCountMap[key] = dll.begin();
        } else {
           auto curNode = keyCountMap[key];
            int curCount = curNode->count;
            auto nextNode = next(curNode);

            if (nextNode == dll.end() || nextNode->count != curCount + 1) {
                nextNode = dll.insert(nextNode, Node(curCount + 1));
                countNodeMap[curCount + 1] = nextNode;
            }
            
            nextNode->keys.insert(key);
            keyCountMap[key] = nextNode;
            
            curNode->keys.erase(key);
            if (curNode->keys.empty()) {
                countNodeMap.erase(curCount);
                dll.erase(curNode);
            }
        }
    }
    
    void dec(string key) {
        auto curNode = keyCountMap[key];
        int curCount = curNode->count;
        
        if (curCount == 1) {
            keyCountMap.erase(key);
        } else {
            auto prevNode = prev(curNode);
            
            if (curNode == dll.begin() || prevNode->count != curCount - 1) {
                prevNode = dll.insert(curNode, Node(curCount - 1));
                countNodeMap[curCount - 1] = prevNode;
            }
            
            prevNode->keys.insert(key);
            keyCountMap[key] = prevNode;
        }
        
        curNode->keys.erase(key);
        if (curNode->keys.empty()) {
            countNodeMap.erase(curCount);
            dll.erase(curNode);
        }
    }
    
    string getMaxKey() {
        if (dll.empty()) return "";
        return *(dll.back().keys.begin());
    }
    
    string getMinKey() {
        if (dll.empty()) return "";
        return *(dll.front().keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */