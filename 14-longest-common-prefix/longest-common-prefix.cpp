class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string ans;
        int i=0;
        while (true)
        {
            int curr_ch = 0; // current character
            for (auto str : strs)  //str will work as i here ; and at each i another array is present ( like 2d array)
            {
                if (i >= str.size())
                {
                    // out of bound
                    curr_ch = 0; // it is used so that we can exit from second loop as well
                    break;
                }

                // just started
                if (curr_ch == 0)
                {
                    curr_ch = str[i];
                }
                else if (str[i] != curr_ch)
                {
                    curr_ch = 0;
                    break;
                }
            }
            if (curr_ch == 0)
            {
                break;  //breaks from while loop
            }

            ans.push_back(curr_ch);
            i++;
        }
        return ans;
        }
};