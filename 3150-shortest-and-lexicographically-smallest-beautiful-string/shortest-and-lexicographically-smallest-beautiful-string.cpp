class Solution {
public:
    using u128=__uint128_t;
    static string shortestBeautifulSubstring(string& s, int k) { 
        const int n=s.size();
        int minLen=n+1, cnt1=0, len=0;
        u128 xMin=~(u128)0;
        u128 win=0;
        for(int l=0, r=0; r<n; r++){
            bool is1=s[r]=='1';
            win=(win<<1)|is1;
            cnt1+=is1;
            len++;
            while (cnt1>k||(cnt1==k && s[l]=='0')) {
                win&=((u128)1<<(len-1))-1;
                len--;
                cnt1-=(s[l]=='1');
                l++;
            }
            if (cnt1==k){
                if (len<minLen){
                    minLen=len;
                    xMin=win;
                }
                else if (len==minLen && win<xMin)
                    xMin=win;
            }
        }
        return minLen==n+1?"":(bit_cast<bitset<128>>(xMin)).to_string().substr(128-minLen, minLen);
    }
};