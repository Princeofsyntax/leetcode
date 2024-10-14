class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)return 0;
        long long score = 0;
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i],i});
        }

        while(k){
            auto pair = pq.top();
            pq.pop();
            int index = pair.second;
            int val = pair.first;
            score+=val;
            val = ceil(val/3.0);
            nums[index] = val;
            pq.push({val,index});
            k--;
        }

        return score;
    }
};