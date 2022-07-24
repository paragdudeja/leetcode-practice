class FoodRatings {
public:
    struct cmpCust {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    
    
    unordered_map<string, map<pair<int, string>, int, cmpCust>> mp;
    unordered_map<string, string> cus;
    unordered_map<string, int> rat;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            cus[foods[i]] = cuisines[i];
            rat[foods[i]] = ratings[i];
            mp[cuisines[i]].insert({{ratings[i], foods[i]}, 1});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = cus[food];
        int old = rat[food];
        mp[c].erase({old, food});
        mp[c].insert({{newRating, food}, 1});
        rat[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = mp[cuisine].begin();
        return it->first.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */