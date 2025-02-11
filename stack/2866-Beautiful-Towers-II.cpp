class Solution {
    public:
        long long maximumSumOfHeights(vector<int>& v) {
            int n = v.size();
            vector<long long> left(n), right(n);
    
            stack<int> st;
    
            for(int i = 0; i < n; i++) {
                while(!st.empty() && v[st.top()] > v[i]) st.pop();
               
                if (!st.empty()) {
                    left[i] = left[st.top()] + (i-st.top())*1ll*v[i];
                } else {
                    left[i] = (i+1)*1ll*v[i];
                }
    
                st.push(i);
            }
    
            while(!st.empty()) st.pop();
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && v[st.top()] > v[i]) st.pop();
                
                if (!st.empty()) {
                    right[i] = right[st.top()] + (st.top() - i)*1ll*v[i];
                } else {
                    right[i] = (n - i)*1ll*v[i];
                }
                st.push(i);
            }
    
            long long mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, left[i] + right[i] - v[i]);
            }
    
            return mx;
        }
    };