class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(char c : expression){
            if(c == ',') continue;
            if(c == ')'){
                bool hasTrue = false, hasFalse = false;
                while(st.top() == 'f' || st.top() == 't'){
                    if(st.top() == 'f')hasFalse = true;
                    if(st.top() == 't')hasTrue = true;
                    st.pop();
                }
                if(st.top() == '(')st.pop();
                char ch = st.top();
                st.pop();
                if(ch == '!'){
                    if(hasFalse)st.push('t');
                    else st.push('f');
                }
                else if(ch == '&'){
                    if(hasFalse)st.push('f');
                    else st.push('t');
                }
                else{
                    if(hasTrue)st.push('t');
                    else st.push('f');
                }
            }
            else{
                st.push(c);
            }
        }
        return st.top() == 't';
    }
};