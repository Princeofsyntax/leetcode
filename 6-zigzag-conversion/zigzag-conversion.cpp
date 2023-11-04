class Solution {
public:
    string convert(string s, int numRows) {
          if (numRows == 1) 
        {
            return s;
        }
        vector<string> zigzag(numRows); 
        //at each row a string is being stored by putting characters; we will pick string from each to print zigzag
        int i = 0,  row=0;
        bool direction = 1;// top to bottom
        while (true)
        {
            if (direction)
            {
                while (row < numRows && i < s.size())
                {
                zigzag[row++].push_back(s[i++]);
                }
                row = numRows-2; //as index starts from 0
            }
            //when above loop is done, direction becomes 0 as loop breaks
            //else condition will work in opposite way
            else{
                while (row >= 0 && i < s.size()) //i < s.size() is used for safe condition
                {
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1; //as now the loop will work from row 1
            }
            if (i >= s.size())
            {
                break;
            }
            
            direction = !direction; //to change the direction again as start i.e, 1
        }
        string ans = "";
        for (int i = 0; i < zigzag.size(); i++)
        {
            ans += zigzag[i]; //concatenates the strings at various rows
        }
        return ans;
    }
};