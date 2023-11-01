class Solution {
public:
    int myAtoi(string s) {
        int num=0,  i=0, sign=1; //1 means positive
        while (s[i] == ' ')
        {
            i++; //increase until white spaces ends in string
        }
        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign = s[i] == '+' ? 1 : -1; //means is character is + than sign is 1 else -1
            i++;
        }
        while (i < s.size() && isdigit(s[i])) //isdigit is STL function --> returns 1 for digits else 0  
        {
            if (num > INT_MAX/10 || (num == INT_MAX/10 && s[i] > '7')) //this is done because when we multiply 10 at last step (used below) then it goes out of bound
            {
                return sign == 1 ? INT_MAX : INT_MIN; //if sign is 1 , return INT_MAX else INT_MIN
            }
            
            num= num*10 + (s[i] - '0'); //converts into integer from character
            i++;
        }
        
        return num * sign; 
    }
};