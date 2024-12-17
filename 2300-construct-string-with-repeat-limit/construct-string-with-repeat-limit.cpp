class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                pq.push({i, freq[i]}); 
            }
        }
        string result = "";
        while (!pq.empty()) {
            auto [currCharIdx, currFreq] = pq.top(); pq.pop();
            int useCount = min(repeatLimit, currFreq);
            result.append(useCount, 'a' + currCharIdx);
            currFreq -= useCount;
            if (currFreq > 0) {
                if (pq.empty()) break; 
                auto [nextCharIdx, nextFreq] = pq.top(); pq.pop();
                result.push_back('a' + nextCharIdx);
                nextFreq--;
                if (nextFreq > 0) pq.push({nextCharIdx, nextFreq});
                pq.push({currCharIdx, currFreq});
            }
        }
        return result;
    }
};