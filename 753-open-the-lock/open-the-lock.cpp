class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> seen (deadends.begin(), deadends.end()); //initialising the seen set
        //base case
        if(target == "0000"){
            return 0;
        }
        if(seen.count("0000")){
            //provides the count that the given string exist or not
            return -1;
        }
        int ans = 0;
        queue<string>q{{"0000"}}; //push initially "0000"

        while(!q.empty()){
            ++ans; //valid turn
            for(int w = q.size(); w > 0 ; w-- ){
                string word = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    //CASE 1 -> moving forward
                    char cache = word[i];
                    if(word[i] == '9'){
                        word[i] = '0';
                    }
                    else{
                        word[i] = word[i]+1;
                    }

                    //check
                    if(word == target) return ans;
                    if(!seen.count(word)){
                        seen.insert(word);
                        q.push(word);
                    }
                    
                    //CASE 2 -> moving backward
                    word[i] = cache; //bring back the original word
                    if(word[i] == '0'){
                        word[i] = '9';
                    }
                    else{
                        word[i] = word[i] - 1;
                    }
                    
                    //check
                    if(word == target) return ans;
                    if(!seen.count(word)){
                        seen.insert(word);
                        q.push(word);
                    }
                    word[i] = cache; //re-initialise
                }
            }
        }
        return -1;
    }
};