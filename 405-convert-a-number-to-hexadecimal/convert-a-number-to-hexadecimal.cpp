class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0"; 
        
        string hexMap = "0123456789abcdef";
        string result = "";
        unsigned int n = num;  
        
       while (n != 0) {
            int remainder = n & 15; 
            result = hexMap[remainder] + result; 
            n = n >> 4; 
        }
        
        return result;
    }
    
};