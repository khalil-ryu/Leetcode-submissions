class FoodRatings {
    public:
        struct Compare {
            bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first > b.first; // Descending order of ratings
            }
        };
    
        map<string, set<pair<int, string>, Compare>> mp1; // cuisine(rate, food)
        map<string, pair<string, int>> mp2; // food(cuisine, rate)
    
        FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
            for (int i = 0; i < f.size(); i++) {
                mp1[c[i]].insert({r[i], f[i]});
                mp2[f[i]] = {c[i], r[i]};
            }
        }
    
        void changeRating(string f, int nr) {
            pair<string, int> p = mp2[f];
            mp2[f].second = nr;
            mp1[p.first].erase({p.second, f});
            mp1[p.first].insert({nr, f});
        }
    
        string highestRated(string c) {
            return (mp1[c].begin())->second;
        }
    };
    
    /**
     
    Your FoodRatings object will be instantiated and called as such:
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    obj->changeRating(food, newRating);
    string param_2 = obj->highestRated(cuisine);*/