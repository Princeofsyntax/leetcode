class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;       
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int setBit1 = countSetBits(num1); 
        int setBit2 = countSetBits(num2); 
        if (setBit1 == setBit2) return num1;
        int ans = num1; 
        if (setBit1 > setBit2){
            int bitsToUnset = setBit1 - setBit2;
            for (int i = 0; i < 32 && bitsToUnset > 0; ++i) {
                if (ans & (1 << i)) { 
                    ans &= ~(1 << i); // Unset the bit
                    bitsToUnset--;  
                }
            }
        } 
        else {
            // Increase the number of set bits in num1 to match num2
            int bitsToSet = setBit2 - setBit1;
            for (int i = 0; i < 32 && bitsToSet > 0; ++i) {
                if (!(ans & (1 << i))) { // Check if the bit is unset
                    ans |= (1 << i);    // Set the bit
                    bitsToSet--;        
                }
            }
        }
        return ans; 
    }
};
