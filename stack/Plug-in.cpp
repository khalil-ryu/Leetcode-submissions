int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
       string s;
       cin >> s;
       string st;
       for(auto x : s) {
            if (!st.empty() && st.back() == x) st.pop_back();
            else st.push_back(x);
       }
       cout << st << endl;
           
    } 
    return 0;
}
