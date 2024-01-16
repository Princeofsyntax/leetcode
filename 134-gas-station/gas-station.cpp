class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0; //it is the extra gas needed whenever circular route fails due to shortage
        int balance = 0; //it is the gas left in the car after reaching desired destination
        int start = 0;

        for(int i = 0; i<gas.size(); i++){
            balance += gas[i] - cost[i]; //extra gas 
            if(balance < 0){
                deficit  += balance;
                start =  i+1;
                balance = 0; //new refil
            }

        }
       if(deficit + balance >= 0){
           return start;
       }
       else{
           return -1;
       }
    }
};