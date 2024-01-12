class MinStack {
public:
    vector<pair<int,int>> st; //will store the value and current minimum number yet
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int>p = make_pair(val,val); //make_pair is a function used in making pair--> at start first val is min
            st.push_back(p);
        }
        else{
            pair<int,int>p;
            p.first = val;
            p.second = min(val, st.back().second); //back() means last inserted (top) 
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
       return st.back().first;
    }
    
    int getMin() {
        return st.back().second; //as second will have minimum value
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */