struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] != b[0])
            return a[0] > b[0];  
        return a[1] > b[1];      
    }
};

class TaskManager {
public:
    set<vector<int>, compare> st;
    unordered_map<int, vector<int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto x : tasks) {
            st.insert({x[2], x[1], x[0]});
            mp[x[1]] = {x[0], x[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId, userId});
        mp[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto x = mp[taskId];
        st.erase({x[1], taskId, x[0]});
        st.insert({newPriority, taskId, x[0]});
        mp[taskId] = {x[0], newPriority};
    }
    
    void rmv(int taskId) {
        auto x = mp[taskId];
        st.erase({x[1], taskId, x[0]});
        mp.erase(taskId);
    }
    
    int execTop() {
        if (!st.size()) return -1;
        auto x = *st.begin();
        st.erase(st.begin());
        return x[2];
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */