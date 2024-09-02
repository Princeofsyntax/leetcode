class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        int chalkUse;
        if(sum <= k){
            chalkUse = k%sum;
        }
        else{
            chalkUse = k;
        }
        int student;
        for(int i = 0; i < n; i++){
            if(chalk[i] > chalkUse){
               student = i;
               break;
            }
            chalkUse -= chalk[i];
        }

        return student;
    }
};