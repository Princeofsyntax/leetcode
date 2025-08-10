class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string given = to_string(n);
        sort(given.begin(), given.end());
        //2^30 is greater than 10^9
        for(int i = 0; i < 30; i++){
            int x = 1 << i;
            string to_compare = to_string(x);
            sort(to_compare.begin(), to_compare.end());
            if(given == to_compare) return true;
        }
        return false;
    }
};