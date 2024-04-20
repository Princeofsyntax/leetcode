class Solution {
public:
    string minWindow(string s, string p) {
        
        int len1 = s.length();
        int len2 = p.length();
        int start = 0;
        int ansIndex = -1;
        int ansLength = INT_MAX;
        
        
        if(len1 < len2){
            return "";
        }
        
        unordered_map<char,int>strMap;
        unordered_map<char,int>patMap;
        
        //To keep track of all charactersof p string
        for(int i = 0; i < p.length(); i++){
            char ch = p[i];
            patMap[ch]++;
        }
        
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            strMap[ch]++;
            //check for valid character
            if(strMap[ch] <= patMap[ch]){
                count++;
            }
            if(count == len2){
                //window is ready
                
                //minimise the window --> decreasing frequency , moving start forward, answer update
                while( (strMap[s[start]] > patMap[s[start]]) || patMap[s[start]] == 0  )
                {
                    if(strMap[s[start]] > patMap[s[start]]){
                        strMap[s[start]]--;
                    }
                    start++;
                }
                //ans update
                int lengthOfWindow = i - start + 1;
                
                if(lengthOfWindow < ansLength){
                    ansLength = lengthOfWindow;
                    ansIndex = start;
                }
            }
            
        }
        
        if(ansIndex == -1){
            return "";
        }
        else{
            return s.substr(ansIndex, ansLength);
        }
        
    }
};