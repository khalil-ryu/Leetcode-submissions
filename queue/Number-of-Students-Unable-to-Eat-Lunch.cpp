class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            queue<int> q;
            stack<int> st;
            for(auto x : students) q.push(x);
            for(int i = sandwiches.size()-1; i >= 0; i--) {
                st.push(sandwiches[i]);
            }
    
            for(int sz = q.size(); !st.empty(); sz = q.size()) {
                int cur = sz; // 4
                while(cur--) { // 4
                    int x = q.front();
                    int y = st.top();
                    if (x == y) {
                        q.pop(); // 3
                        st.pop();
                    } else {
                        q.pop();
                        q.push(x);
                    }
                }
                // 4
                if (sz == q.size()) return q.size(); // this peoples will never eat
            }
            return 0;
        }
    };