class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //sort the given people array first
        sort(people.begin(), people.end()); //so that light persons comes at start and heavy at last
        
        //two pointers approach
        int start = 0;
        int end = people.size()-1;

        int boats = 0;

        while(start <= end){
            //check if we can place light person with heave person ELSE we will place only heavy person on boat
            if(people[start] + people[end] <= limit){
                start++; //include light person
            }
            end--; //heavy person included in each iteration

            boats++;
        }
      return boats;
    }
};