class Solution {
public:
    string smallestNumber(string pattern) {
         string result;
        stack<char> stack;
        char currentDigit = '1'; 
        for (int i = 0; i <= pattern.length(); ++i) {
            stack.push(currentDigit++);
            if (i == pattern.length() || pattern[i] == 'I') {
                while (!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
            }
        }
        return result;
    }
};