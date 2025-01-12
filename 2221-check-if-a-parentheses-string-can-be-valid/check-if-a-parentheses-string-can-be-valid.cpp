class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        int openCount = 0;
        //Left-to-right traversal: Ensure no excess ')' 
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                openCount++;  //Flexible slot: can act as '('
            } else if (s[i] == '(') {
                openCount++;
            } else {
                openCount--;  //Use '(' to balance ')'
            }
            if (openCount < 0) return false;  
        }
        int closedCount = 0;
        // Right-to-left traversal: Ensure no excess '('
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '0') {
                closedCount++;  // Flexible slot: can act as ')'
            } else if (s[i] == ')') {
                closedCount++;
            } else {
                closedCount--;  // Use ')' to balance '('
            }
            if (closedCount < 0) return false;  
        }
        return true;
    }
};