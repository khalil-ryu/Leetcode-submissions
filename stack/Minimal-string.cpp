int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        string s;
        cin >> s;
        string t =  s;
        vector<int> mn(s.size());
        mn[s.size()-1] = s[s.size()-1]-'a';
        for(int i = s.size()-2; i >= 0; i--) {
            mn[i] = min(mn[i+1], s[i]-'a');
        }
        
        stack<char> st;
        for(int i = 0; i < s.size(); i++) { // acdbb
            while(!st.empty() && mn[i] >= st.top()) {
                cout << char(st.top()+'a'); 
                st.pop();
            }
            st.push(s[i]-'a');
        }
        while(!st.empty()) {
            cout << char(st.top()+'a'); 
            st.pop();
        }
    }


    return 0;
}