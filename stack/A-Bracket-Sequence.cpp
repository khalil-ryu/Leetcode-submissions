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
        mp[']'] = '[';
        mp[')'] = '(';
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {
            if (!st.empty() && mp[s[i]] == s[st.top()]) {
                st.pop();
            } else st.push(i);
        }
        map<int,int> mp2;
        while(!st.empty()) {
            mp2[st.top()] = 1;
            st.pop();
        }
        string ans;
        int mx = 0;
        for(int i = 0; i < s.size();) {
            int cnt = 0;
            string cur = "";
            while(i < n && mp2[i]) i++;
            while(i < n && !mp2[i]) {
                cur += s[i];
                if (s[i] == '[') cnt++;
                i++;
            }
    
            if (cnt > mx) {
                ans = cur;
                mx = cnt;
            }
        }
        cout << mx << endl;
        cout << ans << endl;
        
        
        
    }
 
 
    return 0;
}