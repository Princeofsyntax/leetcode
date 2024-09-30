
class CustomStack {
private:
    int maxSize;
    vector<int> stack;
    vector<int> incrementArr;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        incrementArr.resize(maxSize, 0); 
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        int index = stack.size() - 1;
        if (index == -1) {
            return -1; 
        }
        
        int result = stack[index] + incrementArr[index]; 
        
        if (index > 0) {
            incrementArr[index - 1] += incrementArr[index];
        }
        
        incrementArr[index] = 0; 
        stack.pop_back(); 
        return result;
    }
    
    void increment(int k, int val) {
        int limit = std::min(k, (int)stack.size());
        if (limit > 0) {
            incrementArr[limit - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */