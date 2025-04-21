#include <bits/stdc++.h>
#define ve vector
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define pb push_back
#define ll long long
#define fi first
#define se second
#define optimise ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll INF = 1e18;
const int nax = 2e6+10;
const int MOD = 1e9+7;

int main() {
    optimise;
    int t;
    cin >> t;
    //t = 1;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n), b(m);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int,int> mp1, mp2;
        
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            mp1[b[i]]++;
        }
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < m; i++) {
            mp2[a[i]]++;
            if (mp2[a[i]] <= mp1[a[i]]) cur++;
        }
        for(int i = 0; i < n-m; i++) {
            if (cur >= k) ans++;
            mp2[a[i]]--;
            if (mp1[a[i]] > mp2[a[i]]) cur--;
            mp2[a[i+m]]++;
            if (mp1[a[i+m]] >= mp2[a[i+m]]) cur++;
        }
        if (cur >= k) ans++;
        cout << ans << endl;
    }


    return 0;
}
