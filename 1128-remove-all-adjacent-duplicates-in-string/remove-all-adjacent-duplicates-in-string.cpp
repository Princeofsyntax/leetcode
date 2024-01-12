class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        for(auto ch : s)
        {
            if( !st.empty() && st.top() == ch)
            {
                st.pop(); //to remove paired characters
            }
            else
            {
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        //as stack provide reverse order therefore we will reverse again and then return
        reverse(ans.begin(), ans.end());
        return ans;
    } 
};