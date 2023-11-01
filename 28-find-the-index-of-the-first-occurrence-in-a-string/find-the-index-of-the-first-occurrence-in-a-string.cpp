class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        // sliding window
        for (int i = 0; i <= n - m; i++) // n-m is used to not check string matching when it goes out of bound
        {
            for (int j = 0; j < m; j++)
            {
                if (needle[j] != haystack[i + j])
                {
                    break;
                }
                if (j == m - 1) // all traversed with matching
                {
                    return i;
                }
            }
        }
        return -1;
        }
};