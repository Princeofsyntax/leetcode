class Solution {
public:
    
    static bool myComp(string a, string b) // as the snums is string vector, myComp will take any two string
    {
        // we have to overcome the case of like "3","30"--> 330 or 303
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2; // returns which is largest
    }
    string largestNumber(vector<int>& nums) {
         vector<string> snums; // to convert the given integer vector in string vector
        for (auto n : nums)   // n in nums
        {
            snums.push_back(to_string(n));
        }
        sort(snums.begin(), snums.end(), myComp); // custom comparator sort in our wayy--> here descending
        if (snums[0] == "0")
        {
            return "0"; // as after sorting if 0 is largest then only 0 is the answer-->done to avoid 000..
        }

        string ans;
        for (auto str : snums)
        {
            ans += str;
        }
        return ans;
    }
};