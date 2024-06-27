class Solution {
public:
    int mostFrequent(vector<int> &arr, int n) 
    { 
        // Insert all elements in hash. 
        unordered_map<int, int> hash; 
        for (int i = 0; i < n; i++) 
            hash[arr[i]]++; 
    
        // find the max frequency 
        int max_count = 0, res = -1; 
        for (auto i : hash) { 
            if (max_count < i.second) { 
                res = i.first; 
                max_count = i.second; 
            } 
        } 
    
        return res;  
    } 

    int findCenter(vector<vector<int>>& edges) {
        vector<int>arr;

        for(int i = 0; i < edges.size(); i++){
            for(int j = 0; j < 2; j++){
                arr.push_back(edges[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        return mostFrequent(arr, arr.size());
    }
};