class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n == 1) return true;
        bool oneBit = true;
        for(int i = 0; i < n; ){
            if(bits[i] == 0) i++;
            else{
                i += 2;
                if(i >= n) oneBit = false;
            }
        }
        return oneBit;
    }
};