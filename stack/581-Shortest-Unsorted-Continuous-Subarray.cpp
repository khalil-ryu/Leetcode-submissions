class Solution {
    public:
        int findUnsortedSubarray(vector<int>& v) {
            int n = v.size();    
            vector<int> l(n, -1), r(n, -1);
    
            stack<int> st;
            for(int i = 0; i < n; i++) {
                while(!st.empty() && v[st.top()] > v[i]) l[st.top()] = i, st.pop();
                st.push(i);
            }
    
            while(!st.empty()) st.pop();
            
            for(int i = n-1; i >= 0; i--) {
                while(!st.empty() && v[st.top()] < v[i]) r[st.top()] = i, st.pop();
                st.push(i);
            }
            int x = 0, y = n-1;
            while( x < n && l[x] == -1) x++; while(y > x && r[y] == -1) y--;
    
            return y-x+1;
    
        }
    };