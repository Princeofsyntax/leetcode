class Solution {
    bool canAssign(int mid,vector<int>& workers,vector<int>& tasks,int pills,int strength){
        multiset<int> usable_workers(workers.end()-mid,workers.end());
        for(int i=mid-1;i>=0;--i){
            auto curr_worker = --usable_workers.end();

            if(*curr_worker < tasks[i]){
                if(pills<=0)    return false;
                
                //Optimal Strategy: Assign weakest worker to get the current task done
                auto weakest_worker = usable_workers.lower_bound(tasks[i]-strength);
                if(weakest_worker==usable_workers.end())
                    return false;//No one can be assigned the current job (even using pill)
                
                pills--;
                usable_workers.erase(weakest_worker);
            }else
                usable_workers.erase(curr_worker);
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(),workers.end());
        sort(tasks.begin(),tasks.end());
        int low = 0;
        int high = min(tasks.size(),workers.size());
        int mid;

        int assigned = 0;
        while(low <= high){
            mid = low+(high-low)/2;
            if(canAssign(mid,workers,tasks,pills,strength)){
                assigned = mid;
                low = mid+1;
            }else
                high = mid-1;
        }
        return assigned;
    }
};