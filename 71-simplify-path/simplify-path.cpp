class Solution {
public:
    void buildAns(stack<string>&s, string &ans){
        //reverse the stack to get the answer-->minPath
        if(s.empty()){
            return;
        }
        string minPath = s.top() ;
        s.pop();
        buildAns(s,ans);
        ans += minPath; //reverse 
    }

    string simplifyPath(string path) {
        stack<string>s;
        int i = 0;
        while(i < path.size()){
            int start = i;
            int end = i+1; //so that we can consider two characters 
            while( end < path.size() && path[end] != '/'){
                ++end;
            }
            i = end;
            string minPath = path.substr(start, end-start); //start and length
            // cout<<minPath<<endl;
            if(minPath == "/"|| minPath == "/."){
                continue;
            }
            if(minPath != "/.."){
               s.push(minPath);
            }
            else if( minPath == "/.." && !s.empty()){
               s.pop();
            }
        }
        string ans = s.empty() ? "/" : ""; //if and else condition
        buildAns(s,ans);
        return ans;
    }
};