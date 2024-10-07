class Solution {
public:
    int minLength(string s) {
        stack<char> helper;  
        for (char c : s) {
           if (!helper.empty() && 
                ((helper.top() == 'A' && c == 'B') || (helper.top() == 'C' && c == 'D'))) {
                helper.pop(); 
            }
            else {
                helper.push(c);  
            }
        }
        
        return helper.size(); 
    }
};