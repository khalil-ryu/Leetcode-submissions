
class MyCalendarTwo {
    public:
        map<int,int> mp;
        MyCalendarTwo() {
    
        }
        
        bool book(int startTime, int endTime) {
            int event = 0;
            mp[startTime]++;
            mp[endTime]--;
            for(auto & [time, count] : mp) {
                event += count;
                if (event == 3) {
                    mp[startTime]--;
                    mp[endTime]++;
                    return false;
                }
            }
            return true;
        }
    };
    
    /**
     * Your MyCalendarTwo object will be instantiated and called as such:
     * MyCalendarTwo* obj = new MyCalendarTwo();
     * bool param_1 = obj->book(startTime,endTime);
     */