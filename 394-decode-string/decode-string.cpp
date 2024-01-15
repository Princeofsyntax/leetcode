class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        for(auto ch:s)
        {
            if(ch == ']')
            {
                string stringToRepeat = ""; //the string which is to be repeated
                while(!st.empty() && st.top() != "[")
                {
                    string top = st.top();
                    stringToRepeat += top ;
                    st.pop();
                }
                st.pop(); //to pop "["

                //when the count upto which we have to repeat is more than single digit than we have to consider them all
                string numericTimes = ""; //how many times we have to repeat the stringToRepeat
                while(!st.empty() && isdigit(st.top()[0]))//isdigit() takes a char but we have pushed string-->take[0]
                {
                        numericTimes += st.top();
                        st.pop();
                }
                reverse(numericTimes.begin() , numericTimes.end()); //so that we get actual number to which we have to repeat
                int n = stoi(numericTimes); //conversion of string to integer

                //final decoding
                string currDecodeString = "";
                while(n--)
                {
                    currDecodeString += stringToRepeat;
                }
                st.push(currDecodeString); //push the decoded string in stack for next pass
            }
            else{
                string temp(1 , ch); //converts character ch into string as stack is of stirng
                st.push(temp);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top(); //stack top contains currDecodeString --> we have to reverse them
            st.pop();
        }
        //reverse the answer to get real answer
        reverse(ans.begin(), ans.end());

        return ans;
    }
};