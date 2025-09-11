class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        set<char>st = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
        vector<int>indices;
        priority_queue<char, vector<char>, greater<char>> pq;
        for(int i = 0; i < n; i++){
            if(st.count(s[i])){
                indices.push_back(i);
                pq.push(s[i]);
            }
        }
        if(indices.empty()) return s;
        int i = 0;
        while(!pq.empty()){
            s[indices[i++]] = pq.top();
            pq.pop();
        }
        return s;
    }
};