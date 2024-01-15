class Solution {
    class Car{
        public: 
            int pos, speed;
            //constructor
            Car(int p, int s): pos(p), speed(s) {};
    };
    static bool myComp(Car &a, Car&b){
        return a.pos < b.pos ; //sorting w.r.t position
            }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars; 
        //using class car-->pos,speed-->we will sort position -->speed will be according to position
        for(int i = 0; i<position.size(); i++){
         Car car(position[i], speed[i]);
         cars.push_back(car); 
        }
        sort(cars.begin(), cars.end(), myComp); //using myComp we will define w.r.t whom sorting to be done

        //main code begins
        stack<float>st;
        for(auto car: cars){
            float time = (target - car.pos)/ ((float)car.speed); //to calculate time to reach destination
            
            while( !st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};