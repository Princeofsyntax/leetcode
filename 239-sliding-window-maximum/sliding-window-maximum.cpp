class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq; // < value, index >
        vector<int>ans;

        //consider first window
        for(int i = 0; i < k; i++){
            pq.push({ nums[i],i });
        }

        //store first window max
        ans.push_back(pq.top().first);

        //consider rest of the windows
        for(int i = k; i< nums.size(); i++){
            pq.push({nums[i],i});

            //remove if max is from previous window
            while( pq.top().second <= i-k){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }
        return ans;
    }
};