class Solution {
public:
    string flipReverse(string &X){
        for(int i = 0; i < X.size(); i++){
            if(X[i] == '1') X[i] = '0';
            else X[i] = '1';
        }
        reverse(X.begin(), X.end());
        return X;
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        n = n-1;
        while(n--){
            s = s + '1' + flipReverse(s);
        }
        return s[k-1];
    }
};