class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;

        vector<long long>count(26,0);
        for(const auto& ch : s)count[ch-'a']++;

        for(int transformation = 0; transformation < t; transformation++){
            // long long zCount = count[25];

            // for(int i = 24; i >= 0; i--){
            //     count[i+1] = count[i];
            // }
            // count[0] = 0;
            // count[25] = zCount;
            // count[0] = (count[0] + zCount)%MOD;
            // count[1]= (count[1] + zCount)%MOD;
            vector<long long>charCounts(26,0);
            for(int i = 0; i < 26; i++){
                if(i == 25){
                    charCounts[0] = (charCounts[0]+count[i])%MOD;
                    charCounts[1] = (charCounts[1] + count[i])% MOD;
                }
                else{
                    charCounts[i+1] = (charCounts[i+1] + count[i])% MOD;
                }
            }
            count = charCounts;
        }

        
        long long finalLength = 0;
        for(long long c : count){
            finalLength = (finalLength + c)%MOD;
        }
        return (int)finalLength;
    }
};