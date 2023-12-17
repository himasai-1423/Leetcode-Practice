class Food {
public:
    int rating; 
    string name;
    Food(int rating, string name) {
        this->rating = rating;
        this->name = name;
    }
    
    bool operator<(const Food &other) const {
        if(rating == other.rating) {
            return name>other.name;
        }
        
        return rating < other.rating;
    }
};

class FoodRatings {
public:
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    
    unordered_map<string, priority_queue<Food>> cuisineFoodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++) {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
         foodRatingMap[food] = newRating;
       
        auto cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
        
    }
    
    string highestRated(string cuisine) {
         auto highestRated = cuisineFoodMap[cuisine].top();
        
        while (foodRatingMap[highestRated.name] != highestRated.rating) {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }
    
        return highestRated.name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */