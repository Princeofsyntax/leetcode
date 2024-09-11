class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start^goal;
        int count = 0;
        while(temp){
            if(temp&1 == 1){
                count++;
            }
            temp = temp>>1;
        }
        return count;
    }
};