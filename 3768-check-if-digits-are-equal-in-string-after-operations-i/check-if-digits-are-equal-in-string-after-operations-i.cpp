class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string temp = "";
            int n = s.size();
            for (int i = 0; i < n - 1; i++) {
                int sum = (s[i] - '0' + s[i+1] - '0') % 10;
                temp.push_back(sum + '0');
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};