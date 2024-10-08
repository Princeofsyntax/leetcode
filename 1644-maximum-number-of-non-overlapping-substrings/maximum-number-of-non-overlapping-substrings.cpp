class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < n; i++) {
            if (i == first[s[i] - 'a']) {  
                int start = i;
                int end = last[s[i] - 'a'];
                int j = start;
                
                
                while (j <= end) {
                    if (first[s[j] - 'a'] < start) {
                        start = first[s[j] - 'a'];
                    }
                    end = max(end, last[s[j] - 'a']);
                    j++;
                }
                
                // Only push the interval if it starts at i (to avoid duplicates)
                if (start == i) {
                    intervals.push_back({start, end});
                }
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        
        vector<string> result;
        int prev_end = -1;
        
        for (auto& interval : intervals) {
            int start = interval.first;
            int end = interval.second;
            if (start > prev_end) {
                result.push_back(s.substr(start, end - start + 1));
                prev_end = end;
            }
        }
        
        return result;
    }
};
