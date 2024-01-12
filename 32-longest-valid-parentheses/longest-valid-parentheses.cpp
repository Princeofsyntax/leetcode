class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1); //as indexing is from 0, -1 will help in length calculation
        int maxLen = 0; //as in question minimum length is 0
        for(int i = 0; i< s.length(); i++){
            char ch = s[i];
            if( ch == '('){
              st.push(i); //so that at last we can take difference to get length
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int length = i - st.top();
                    maxLen = max(maxLen, length);
                }

            }
        }
        return maxLen;
    }
};