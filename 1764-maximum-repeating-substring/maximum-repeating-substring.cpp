class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;  
        string repeatedWord = word;  
        
        while (sequence.find(repeatedWord) != string::npos) {
            k++;  
            repeatedWord += word;  
        }
        
        return k;  
    }
};