int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        int x = 0, y = 0;

        map<int,int> mp, mp2, X, Y;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            X[x]++;
            Y[y]++;
            mp[y-x]++; mp2[y+x]++;
        }
        ll ans = 0;
        for(auto x : X) ans += x.se*1ll*(x.se-1);
        for(auto y : Y) ans += y.se*1ll*(y.se-1);
        for(auto x : mp) ans += x.se*1ll*(x.se-1);
        for(auto x : mp2) ans += x.se*1ll*(x.se-1);
        cout << ans << endl;

    }

    return 0;
}
