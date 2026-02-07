class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;   // number of 'b' seen so far
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { 
                //either delete this 'a' OR delete all previous 'b'
                deletions = min(deletions + 1, bCount);
            }
        }
        return deletions;
    }
};
