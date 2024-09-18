class Solution {
public:
    static bool myComp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string>helper;
        for(const auto& num : nums){
            helper.push_back(to_string(num));
        }

        sort(helper.begin(), helper.end(), myComp);
        if(helper[0] == "0"){
            return "0";
        }

        string ans = "";
        for(const auto& help: helper){
            ans += help;
        }

        return ans;
    }
};