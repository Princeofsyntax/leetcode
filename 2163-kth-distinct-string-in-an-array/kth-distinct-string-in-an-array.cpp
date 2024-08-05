class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        // Count the frequency of each string
        for (const auto& str : arr) {
            freq[str]++;
        }

        int count = 0;

        // Iterate over the input array to maintain order
        for (const auto& str : arr) {
            if (freq[str] == 1) {
                count++;
                if (count == k) {
                    return str;
                }
            }
        }

        return "";

        
    }
};