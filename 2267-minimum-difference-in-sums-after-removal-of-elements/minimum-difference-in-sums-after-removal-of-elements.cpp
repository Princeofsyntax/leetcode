class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<ll>prefix(nums.size(), -1) , suffix(nums.size(), -1);
        //prefix[i] stores sum of first n elements from left side --> to have minimum sum
        //suffix[i] stores sum of first n elements from right side --> to have maximum sum

        ll sum = 0;  //minimum n elements sum
        priority_queue<ll>pq; //maxHeap
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pq.push(nums[i]);

            //pop out maximum element
            if(pq.size() > n){
                sum -= pq.top(); //so that minimum sum can be achieved
                pq.pop();
            }
            if(pq.size() == n){
                prefix[i] = sum;
            }
        }
        sum = 0; // maximum n elements sum
         priority_queue<ll, vector<ll>, greater<ll>>pq2; //minHeap
        for(int i = nums.size()-1; i >= 0 ; i--){
            sum += nums[i];
            pq2.push(nums[i]);

            //pop out minimum element
            if(pq2.size() > n){
                sum -= pq2.top(); //so that maximum sum can be achieved
                pq2.pop();
            }
            if(pq2.size() == n){
                suffix[i] = sum;
            }
        }
        ll ans = LONG_LONG_MAX;
        for(int i = n-1; i < 2*n; ++i){
            ans = min(ans, prefix[i]-suffix[i+1]);
        }
        return ans;
    }
};