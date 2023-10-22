class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256] = {0}; // initialses to zero
        for (int i = 0; i < s.size(); i++)
            {
                freqTable[s[i]]++; // s[i] is typecasted in integer and then increases the value at that index by 1
            }

        for (int i = 0; i < t.size(); i++)
            {
                freqTable[t[i]]--; // decrease by 1 at that index jaha value aaega
            }

        for (int i = 0; i < 256; i++)
            {
                if (freqTable[i] != 0)
                {
                    return false;
                }
            }

    return true;
    }
};