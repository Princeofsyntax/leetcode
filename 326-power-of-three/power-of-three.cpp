class Solution {
public:
    bool isPowerOfThree(int n) {
        //powers of 3 must be positive. 0 and negative numbers are not.
        if (n <= 0) return false;
        
        //calculate log base 3 of n
        double log_result = log(n) / log(3);
        
        //a small tolerance to handle floating-point inaccuracies
        const double EPSILON = 1e-10; 
        
        //check if the result is very close to its nearest integer
        return abs(log_result - round(log_result)) < EPSILON;
    }
};