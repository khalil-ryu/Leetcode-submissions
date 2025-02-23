int main() {
    optimise;
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        int cum = 0;
        for(auto x : s) {
            if (x == '(') cnt++;
            else cnt--;
            if (cnt < 0) cum++, cnt = 0;
        }
        
        cout << s.size() - cnt - cum << endl;
    }
 
 
    return 0;
}