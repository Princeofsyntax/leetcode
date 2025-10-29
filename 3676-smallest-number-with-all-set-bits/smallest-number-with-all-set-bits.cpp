class Solution {
public:
    int smallestNumber(int n) {
        int result = 0;
        int bitPosition = 0;
        while(n>0){
            result |= (1 << bitPosition);
            n >>= 1;
            bitPosition++;
        }
        return result;
    }
};