class Solution {
public:
    bool canDistributeHelper(vector<int>&counts,vector<int>& quantity, int ith_customer ){
        //base case
        if( ith_customer == quantity.size()){
            return true; //as all customers are satisfied
        }

        for(int i = 0; i < counts.size(); i++){
            if(counts[i] >= quantity[ith_customer]){
                //alot the quantity 
                counts[i] -= quantity[ith_customer];
                //check if next customer can also be alloted
                if( canDistributeHelper(counts,quantity,ith_customer+1)){
                    return true;
                }
                else{
                 //backtracking
                counts[i] += quantity[ith_customer];
                }
            }
        }
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>countMap; //To store the count of integers in nums array (integers as index and values as count)
        for(auto num : nums){
            countMap[num]++;
        }
        vector<int>counts;
        //counts vector stores count of integers of nums acting here like indices
        for(auto it : countMap){
            counts.push_back(it.second); //second means frequency or count
        }
        sort(quantity.rbegin(),quantity.rend());//decreasing order 
        //sorting is done so that bigger element comes first and if false result is supposed to come then it will come earlier-->reduces time complexity
        return canDistributeHelper(counts,quantity,0); //at start we have to satisfy 0th customer
    }
};