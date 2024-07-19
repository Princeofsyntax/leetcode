class SmallestInfiniteSet {
private:
    set<int> set;
    int current;
    
public:
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if (!set.empty()) {
            int smallest = *set.begin();
            set.erase(set.begin());
            return smallest;
        }
        return current++;
    }
    
    void addBack(int num) {
        if (num < current && set.find(num) == set.end()) {
            set.insert(num);
        }
    }
};