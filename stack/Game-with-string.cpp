int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
       string s;
       cin >> s;
       string st;
       int cnt = 0;
       for(auto x : s) {
           if (!st.empty() && x == st.back()) st.pop_back(), cnt++;
           else st.push_back(x);
       }
       cout << (cnt%2 ? "YES" : "NO") << endl;
    }
 
 
    return 0;
}