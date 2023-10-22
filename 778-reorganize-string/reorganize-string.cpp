class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++; // s[0]=a therefore at start the index is hash[0] and then 1,2,3,..
    }

    // find the most frequent character
    char most_freq_char;
    int max_freq = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            most_freq_char = i + 'a';  //so that it mapps with characters
        }
        
    }
    int index = 0;
    while (max_freq > 0 && index < s.size())
    {
        s[index] = most_freq_char;
        max_freq--;
        index += 2;  //so that characters are placed after one gap
    }
    
    //if not able to fill all most_freq_char
    if (max_freq != 0)
    {
        return ""; //null string
    }
    
    hash[most_freq_char - 'a'] = 0; //when all mostly occurred character is placed after gap

    //let's place rest of the characters
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index; //if index >= s.size() then we will make index as 1 else the index will remain what it is
            s[index] = i + 'a'; //to get character
            hash[i]--;
            index += 2;
        }
        
    }
    return s;
    }
};