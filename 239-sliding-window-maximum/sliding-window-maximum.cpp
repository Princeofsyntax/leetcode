class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; //so that push/pop can be done from front and back
        vector<int> ans;

        //first window of k size
        for(int i = 0; i<k; i++){
            //chote element remove krdo
            while( !dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            //inserting index, so that we can check out of window element
            dq.push_back(i);
        }

        //store answer for first window
        ans.push_back(nums[dq.front()]);

        //remaining window process; one one step
        for(int i = k; i<nums.size(); i++)
        {
            //remove out of window element
            if( !dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }
            //again chote element remove krdo
            while( !dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            //inserting index, so that we can check out of window element
            dq.push_back(i);
            
            //store current window answer
            ans.push_back(nums[dq.front()]);
        }
       return ans;
    }
};