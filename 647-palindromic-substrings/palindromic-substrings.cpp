class Solution {
public:
    int expandAroundIndex(string s, int start, int end){
    int count=0;
    while (start>=0 && end<=s.length() && s[start]==s[end])
    {
        count++;
        start--;
        end++;
    }
    return count;
}
    int countSubstrings(string s) {
        int count=0;
    int n=s.length();

    for (int i = 0; i < n; i++)
    {
        //odd
        int oddKaAns=expandAroundIndex(s,i,i);
        count=count+oddKaAns;
        //even
        int evenKaAns=expandAroundIndex(s,i,i+1);
        count=count+evenKaAns;
    }
    return count;
    }
};