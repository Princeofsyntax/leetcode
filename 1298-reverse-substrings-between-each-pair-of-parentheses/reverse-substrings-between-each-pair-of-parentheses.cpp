class Solution {
public:
    void reverseHelper(string&s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseParentheses(string s) {
        stack<int> st;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int left = st.top();
                st.pop();
                reverseHelper(s, left + 1, i - 1);
            }
        }
        
        string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result.push_back(c);
            }
        }
        
        return result;
    }
};