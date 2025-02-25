class MyCalendar {
    public:
        set<pair<int,int>> st;
        MyCalendar() {
            
        }
        
        bool book(int startTime, int endTime) {
            auto it = st.lower_bound({startTime, endTime});
            if (!st.size()) {
                st.insert({startTime, endTime});
                return true;
            }
            if (it != st.end()) {
               if (it->first == startTime) return false;
               else if (it->first < endTime) return false;
               
                if (it != st.begin()) {
                    it--;
                    if (it->second > startTime) return false;
                } 
            
            } else {
                if (st.size()) {
                    it--;
                    if (it->second > startTime) return false;
                }
            }
            st.insert({startTime, endTime});
            return true;
        }
    };
    
    /**
     * Your MyCalendar object will be instantiated and called as such:
     * MyCalendar* obj = new MyCalendar();
     * bool param_1 = obj->book(startTime,endTime);
     */