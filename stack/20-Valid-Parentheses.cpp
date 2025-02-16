class Solution {
    public:
        bool isValid(string s) {
            stack<int> st;
            map<char,char> mp;
            mp['('] = ')';
            mp['['] = ']';
            mp['{'] = '}';
            for(auto x : s) {
                if (!st.empty() && mp[st.top()] == x) st.pop();
                else st.push(x);
            }
            return st.empty();
        }
    };