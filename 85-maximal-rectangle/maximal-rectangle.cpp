class Solution {
public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            if (i < n) {
                st.push(i);
            }
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        //tret this question as histogram question
        if (mat.empty() || mat[0].empty()) return 0;

        int maxArea = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Update histogram heights.
                if (mat[i][j] == '1') // Compare to character '1'.
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
