class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) {
            return result;
        }
        int direction = (k > 0) ? 1 : -1; 
        k = abs(k); 
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 1; j <= k; ++j) {
                sum += code[(i + direction * j + n) % n]; 
            }
            result[i] = sum;
        }
        return result;
    }
};