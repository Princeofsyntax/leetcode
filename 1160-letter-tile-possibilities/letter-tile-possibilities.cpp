class Solution {
public:
    int buildString(vector<int>& freq){
        int ways = 0;
        //Any char can be at current position
        for(int i=0;i<26;++i){
            if(freq[i]>0){//We can use curr char
                freq[i]--;
                ways += 1 + buildString(freq);
                freq[i]++;
            }
        }
        return ways;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char c: tiles)
            freq[c-'A']++;
        return buildString(freq);
    }
};