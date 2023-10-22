class Solution {
public:
    bool isVowel(char ch)
{
     ch=tolower(ch);  //converts in lower case so that we can easily check for aeiou or AEIOU
     return ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ;
}
    string reverseVowels(string s) {
         int l=0;
        int h=s.size()-1;
        while (l<h)
        {
        if (isVowel(s[l]) && isVowel(s[h]))
        {
            swap(s[l], s[h]);
            l++, h--;
        }
        else if( isVowel(s[l]) == 0)  //is false
        {
            l++;
        } 
        else{
            h--;
        }
        }
        return s;   
    }
};