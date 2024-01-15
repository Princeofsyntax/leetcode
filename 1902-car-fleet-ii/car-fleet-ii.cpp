class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double>answer( cars.size(), -1); //collision time of ith car with the next car

        stack<int>st; //we will push indices //indices are from 0
        for(int i = cars.size()-1 ; i>=0 ; i--)//iterating from back
        {
            //check if car ahead of current car is faster?
            while( !st.empty() && cars[st.top()][1] >= cars[i][1]) //1 is for speed and 0 for position
            {
                st.pop();
            }

            while(!st.empty()){
                //using relative time concept
                double collTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]); 
                if( answer[st.top()] == -1 || collTime <= answer[st.top()])
                {
                    answer[i] = collTime;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        
      return answer;
    }
};