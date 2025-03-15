class StockPrice {
    public:
        set<pair<int,int>> st;
        map<int,int> mp;
        pair<int,int> last;
        StockPrice() {
            
        }
        
        void update(int timestamp, int price) {
            if (mp.find(timestamp) != mp.end()) st.erase({mp[timestamp], timestamp});
            st.insert({price, timestamp});
            if (last.first <= timestamp) last = {timestamp, price};
            mp[timestamp] = price;
        }
        
        int current() {
            return last.second;
        }
        
        int maximum() {
            return st.rbegin()->first;
        }
        
        int minimum() {
            return st.begin()->first;
        }
    };
    
    /**
     * Your StockPrice object will be instantiated and called as such:
     * StockPrice* obj = new StockPrice();
     * obj->update(timestamp,price);
     * int param_2 = obj->current();
     * int param_3 = obj->maximum();
     * int param_4 = obj->minimum();
     */