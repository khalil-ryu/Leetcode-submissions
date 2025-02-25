class TweetCounts {
    public:
        map<string, multiset<int>> mp;
    
        map<string, int> scale_by_string = {
            {"minute", 60},
            {"hour", 3600},
            {"day", 86400},
        };
        
        void recordTweet(string tweetName, int time) {
            mp[tweetName].insert(time);
        }
        
        vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
            vector<int> v;
            int start = startTime;
            int end = min(endTime, start + scale_by_string[freq] - 1);
    
            auto it = mp[tweetName].lower_bound(start);
    
            while(start <= endTime) {
                int cnt = 0;
                while(it != mp[tweetName].end() && *it >= start && *it <= end) it++,cnt++; 
                v.push_back(cnt);
                start = end+1;
                end = min(endTime, start + scale_by_string[freq] - 1);
            }
            return v;
        }
    };
    
    /**
     * Your TweetCounts object will be instantiated and called as such:
     * TweetCounts* obj = new TweetCounts();
     * obj->recordTweet(tweetName,time);
     * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
     */