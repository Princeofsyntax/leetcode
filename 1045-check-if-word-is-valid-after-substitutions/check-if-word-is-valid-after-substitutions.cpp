class Solution {
public:
    bool isValid(string s) {
        int fnd = s.find("abc");
        if(s.size() == 0){
            return true;
        }
        if(fnd != string::npos)//npos means not a position 
        {
            //means string is found
            string tleft = s.substr(0, fnd); //upto fnd count //indexing is from 0 
            string tright = s.substr(fnd+3, s.size()); //because abc length is 3
            return isValid(tleft + tright);
        }
        return false;

    }
};