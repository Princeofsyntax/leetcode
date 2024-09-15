class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> first_occurrence;
          first_occurrence[0] = -1; 

        int bitmask = 0, max_length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a') {
                bitmask ^= (1 << 0); 
             } else if (s[i] == 'e') {
                bitmask ^= (1 << 1); 
             } else if (s[i] == 'i') {
                bitmask ^= (1 << 2); 
            } else if (s[i] == 'o') {
                bitmask ^= (1 << 3); 
          } else if (s[i] == 'u') {
                bitmask ^= (1 << 4); 
            }
            
         if (first_occurrence.find(bitmask) != first_occurrence.end()) {
                max_length = max(max_length, i - first_occurrence[bitmask]);
            } else {
                first_occurrence[bitmask] = i;
            }
        }
        
        return max_length;
    }
};