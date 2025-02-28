int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        stack<int> st;
        string s;
        cin >> s;
        map<char,char> mp;
        mp[')'] = '(';
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {
            if (!st.empty() && mp[s[i]] == s[st.top()]) {
                st.pop();
            } else st.push(i);
        }
        
        ii ans = {0,1};
        int end = n-1;
        while(st.size()) {
            int i = st.top()+1;
            st.pop();
            if (i <= end) {
                int cur = end-i+1;
                if (ans.fi == cur) ans.se++;
                else if (ans.fi < cur) ans.fi = cur, ans.se = 1;
            }
            end = i-2;
        }
        
        int l = 0;
        if (l <= end) {
            int cur = end-l+1;
            if (ans.fi == cur) ans.se++;
            else if (ans.fi < cur) ans.fi = cur, ans.se = 1;
        }
        cout << ans.fi << " " << ans.se << endl;   
    }
    return 0;
}