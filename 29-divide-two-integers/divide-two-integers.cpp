class Solution {
public:
    int divide(int dividend, int divisor) {
        // Check for edge case where dividend is INT_MIN and divisor is -1
        // Since INT_MIN / -1 would overflow, return INT_MAX
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Determine the sign of the result
        // If either dividend or divisor is negative but not both, the result is negative
        const int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        // Convert both dividend and divisor to their absolute values
        long ans = 0; 
        long dvd = labs(dividend); // Absolute value of dividend
        long dvs = labs(divisor); // Absolute value of divisor
        
        // Main division loop
        while (dvd >= dvs) {
            long k = 1; // Initialize the multiplier for divisor
            // Find the largest multiple of divisor such that k * divisor is <= dividend
            while (k * 2 * dvs <= dvd)
                k *= 2;
            // Subtract k * divisor from the dividend
            dvd -= k * dvs;
            // Add k to the result
            ans += k;
        }
        
        // Multiply the result by the sign to give it the correct sign
        return sign * ans;
    }
};
