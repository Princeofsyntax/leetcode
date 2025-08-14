class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        vector<string>help;
        for(int i = 2; i < n; i++){
            if((num[i-2] == num[i-1]) && (num[i-1] == num[i])){
                if(num[i] == '9') return "999";
                help.push_back(num.substr(i-2,3));
            }
        }
        if(help.size() == 0) return "";
        sort(help.rbegin(),help.rend());
        return help[0];
    }
};