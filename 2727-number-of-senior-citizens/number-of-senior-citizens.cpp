class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (const string& detail : details) {
            // Extract the age substring
            string ageStr = detail.substr(11, 2);
            // Convert the age substring to an integer
            int age = stoi(ageStr);
            // Check if the age is strictly more than 60
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};