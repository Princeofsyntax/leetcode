class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //use bfs as it give shortest path ( in first visit )
        queue<pair<string,int>>q; //{word, count}
        q.push({beginWord,1});
        //create a set and copy wordlist in it
        unordered_set<string> st(wordList.begin(), wordList.end());
        //jo bhi word queue me insert hoga usko set me se hata dena hai
        st.erase(beginWord);

        while(!q.empty()){
            pair<string,int> fNode = q.front();
            q.pop();

            string currString = fNode.first;
            int currCount = fNode.second;

            //check if destination is reached
            if(currString == endWord){
                return currCount;
            }

            for(int index = 0; index < currString.length(); index++){
                //har index par jo value hai usko 'a' to 'z' tk replace karna hai
                char originalCharacter = currString[index];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    currString[index] = ch;
                    //check in wordList 
                    if(st.find(currString) != st.end()){
                        //found
                        q.push({currString, currCount+1});
                        st.erase(currString);
                    }
                }
                //backtrack so that other calls can be made
                currString[index] = originalCharacter;
            }
        }
        return 0;

    }
};