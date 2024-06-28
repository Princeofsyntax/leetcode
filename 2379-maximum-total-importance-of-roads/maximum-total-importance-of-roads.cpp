class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // store degree of each cities that how many times they are used in connection
 
        vector<int> degree(n, 0);

        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        // Create a vector of pairs to store each city with its degree
        vector<pair<int, int>> cityDegree;

        for (int i = 0; i < n; i++) {
            // we can also use push_back but for this we have to create pair first and then push it
            // pair<int, int>p = {degree[i],i}; cityDegree.push_back(p)
            cityDegree.emplace_back(degree[i], i);
        }

        // Sort the cityDegree vector in descending order w.r.t degree
        sort(cityDegree.rbegin(), cityDegree.rend());

        // Assign values to the cities
        vector<int> value(n); // Initialize the value vector with size n
        for (int i = 0; i < n; i++) {
            value[cityDegree[i].second] = n - i;
        }

        // Calculate the total importance
        long long totalImportance = 0;

        for (const auto& road : roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }

        return totalImportance;
    }
};