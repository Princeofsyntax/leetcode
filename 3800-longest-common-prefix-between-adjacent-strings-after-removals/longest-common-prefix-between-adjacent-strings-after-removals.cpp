class Solution {
public:
    int similarLen(const string& a, const string& b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) return i;
        }
        return len;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n <= 2) return vector<int>(n, 0);  // base case

        // compute prefix lengths for adjacent pairs
        vector<int> arr(n - 1);
        for (int i = 1; i < n; ++i) {
            arr[i - 1] = similarLen(words[i - 1], words[i]);
        }

        // precompute max to the left and right for optimization
        vector<int> leftMax(n - 1, 0), rightMax(n - 1, 0);
        leftMax[0] = arr[0];
        for (int i = 1; i < n - 1; ++i) {
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }

        rightMax[n - 2] = arr[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // build the result array
        vector<int> ans(n);
        ans[0] = rightMax[1];        // from arr[1] to arr[n-2]
        ans[n - 1] = leftMax[n - 3]; // from arr[0] to arr[n-3]

        for (int i = 1; i < n - 1; ++i) {
            int maxLeft = (i >= 2) ? leftMax[i - 2] : 0;
            int maxRight = (i + 1 < n - 1) ? rightMax[i + 1] : 0;
            int merged = similarLen(words[i - 1], words[i + 1]);
            ans[i] = max({maxLeft, maxRight, merged});
        }

        return ans;
    }
};
