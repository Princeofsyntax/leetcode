class Solution {
public:
    bool canDistribute(int n, vector<int>&quantities, int allowed){
        int totalShopsNeeded = 0;
        for(const auto& q : quantities){
            totalShopsNeeded += (q + allowed - 1)/allowed; // just like ceil function ceil(q/allowed)
            if(totalShopsNeeded > n)return false;
        }
        return true;

    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        while(left <= right){
            int mid = left + (right-left)/2;
            if(canDistribute(n, quantities, mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};