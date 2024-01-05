class Solution {
public:
    void countArrangementHelper( vector<int>&v,int& n, int& ans, int currNum){
        //base case
        if(currNum == n+1){
            //print (just to check)
            // for(int i = 1; i<=n; i++){
            //     cout<<v[i]<<" ";
            // }
            //main process
            ++ans;
            return;
        }

        for(int i = 1; i<=n; ++i){
            if( v[i]==0 && ((currNum % i == 0 ) || (i % currNum == 0))){
              v[i] = currNum;
              countArrangementHelper(v,n,ans,currNum+1);
              //backtracking
              v[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int>v(n+1); //as we want indices from 1 //initialised by 0
        int ans =0;
        countArrangementHelper(v,n,ans,1);
        return ans;
    }
};