class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);  // Initialize the answer array with 0s
        stack<int> st;  // Stack to store indices of temperatures

        for (int i = 0; i < n; ++i) {
            // While the current temperature is greater than the temperature at the index stored in the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                ans[index] = i - index;  // Calculate the number of days
            }
            st.push(i);  // Push the current index onto the stack
        }

        return ans;
    }
};