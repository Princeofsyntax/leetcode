class Solution {
public:
    int minimumDeletions(string word, int k) {
        int ans = INT_MAX;
        vector<int> count(26);  

        for (const char c : word) {
            ++count[c - 'a'];
        }

        //try every frequency as the minimum frequency allowed
        for (const int minFreq : count) {
            int deletions = 0;

            for (const int freq : count) {
                if (freq == 0) continue;  //skip characters not present

                if (freq < minFreq) {
                    //ifrequency is less than minFreq, delete all occurrences
                    deletions += freq;
                } else {
                    //if frequency is more than minFreq + k, delete the extra ones
                    deletions += max(0, freq - (minFreq + k));
                }
            }

            //update the answer with the minimum deletions found
            ans = min(ans, deletions);
        }

        return ans;
    }
};
