class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (c == '*') {
                if (!stk.empty()) {
                    stk.pop(); // Remove the closest non-star character to the left
                }
            } else {
                stk.push(c); // Add non-star characters to the stack
            }
        }
        
        // Construct the resulting string from the characters left in the stack
        std::string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        // The stack gives us the string in reverse order, so we reverse it
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};