class FoodRatings {
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> food_details;
    // cuisine -> set of {-rating, food_name}
    unordered_map<string, set<pair<int, string>>> cuisine_ratings;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            food_details[foods[i]] = {cuisines[i], ratings[i]};
            // Negative rating sorts from highest to lowest in the set.
            // If ratings are tied, set sorts by the lexicographically smaller name.
            cuisine_ratings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // Get old details to remove the previous entry.
        string cuisine = food_details[food].first;
        int oldRating = food_details[food].second;
        
        // Update the sorted set.
        cuisine_ratings[cuisine].erase({-oldRating, food});
        cuisine_ratings[cuisine].insert({-newRating, food});
        
        // Update the food's rating in the details map.
        food_details[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
        // The first element in the set is always the highest-rated food.
        return cuisine_ratings[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */