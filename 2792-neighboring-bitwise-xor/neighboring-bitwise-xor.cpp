class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived){
        int n = derived.size();
        int current = 0; // original[0]
        for (int i = 0; i < n; ++i){
            current = current ^ derived[i]; 
        }
        if (current == 0) return true; 
        current = 1; // original[0]
        for (int i = 0; i < n; ++i){
            current = current ^ derived[i]; 
        }
        if (current == 1) return true; 
        return false;
    }
};