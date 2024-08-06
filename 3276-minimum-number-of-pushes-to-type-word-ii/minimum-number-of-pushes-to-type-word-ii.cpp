class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;

        for(const auto&ch : word){
            mp[ch]++;
        }

        vector<pair<char, int>> vec;

        for (const auto& pair : mp) {
            vec.push_back(pair);
        }

        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });

        int pushCount = 0;
        int count = 0;
        for(const auto&pair : vec){
            count++;
            if(count <= 8){
                pushCount += pair.second;
            }
            else if(count > 8 && count<= 16){
                pushCount += (2*pair.second);
            }
            else if(count > 16 && count <= 24){
                pushCount += (3*pair.second);
            }
            else{
                pushCount += (4*pair.second);
            }
        }

        return pushCount;
    }
};