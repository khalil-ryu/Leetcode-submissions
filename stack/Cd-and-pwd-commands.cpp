vector<string> split(string s) {
    vector<string> ans;
    string cur = "";
    for(int i = 0; i < s.size(); ) {
        if (s[i] == '/') {
            ans.push_back(cur); // vasya/../petya
            cur = "";
            i++;
        }
        while(i < s.size() && s[i] != '/') cur += s[i], i++;
    }
    if (cur.size()) ans.push_back(cur);
    return ans;
}
int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<string> st;
        st.push_back("/");
        while(n--) {
            string command;
            cin >> command;
            string direction;
            if (command == "cd") cin >> direction;
            if (command != "pwd") {
                vector<string> dirs = split(direction);
                if (direction[0] == '/') {
                    st.clear();
                    for(auto x : dirs) st.push_back(x+ '/');
                    continue;
                }
                for(auto x : dirs) {
                    if (x == "..") st.pop_back(); // no need to check always works
                    else st.push_back(x + '/');
                }
            } else {
                for(auto x : st) cout << x;
                cout << endl;
            }
        }
        
        
    }
 
 
    return 0;
}