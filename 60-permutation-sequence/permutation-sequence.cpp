class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>values;
        // calculate (n-1)!
        for(int i = 1; i < n; i++){
            fact = fact*i;
            values.push_back(i);
        }
        values.push_back(n);
        k = k-1; // 0 based indexing
        string ans = "";
        while(true){
            ans += to_string(values[k/fact]);
            values.erase(values.begin() + k/fact);
            if(values.size() == 0) break;
            k = k % fact;
            fact = fact / values.size();
        }

        return ans;
    }
};