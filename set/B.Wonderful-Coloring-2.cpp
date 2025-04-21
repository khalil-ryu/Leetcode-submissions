int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        map<int, vector<int>> pos;
        pos.reserve(n);
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i);
        }
        
        vector<int> ans(n, 0);
        vector<int> small; 
        small.reserve(n);
 
        for (auto &kv : pos) {
            auto &indices = kv.second;
            if ((int)indices.size() >= k) {
                for (int i = 0; i < k; i++) {
                    ans[indices[i]] = i + 1;
                }
            } else {
                for (int idx : indices) {
                    small.push_back(idx);
                }
            }
        }
 
        int totalSmall = small.size();
        int m = totalSmall - (totalSmall % k);
 
        // 4) Round‑robin assign colors 1..k to the first m of `small`
        for (int i = 0; i < m; i++) {
            ans[small[i]] = (i % k) + 1;
        }
 
        // 5) Print result
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
 
    return 0;
}
