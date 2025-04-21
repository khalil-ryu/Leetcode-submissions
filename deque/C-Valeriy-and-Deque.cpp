#include <bits/stdc++.h>

using namespace std;

int main() {
   
    int n, q;
    cin >> n >> q;
    
    deque<int> dq;
    vector<pair<int,int>> preCycle;
    vector<int> cycle;

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
        mx = max(mx, x);
    }

    while (dq.front() != mx) {
        int A = dq.front(); dq.pop_front();
        int B = dq.front(); dq.pop_front();
        
        preCycle.push_back({A, B});
        
        if (A > B) {
            dq.push_front(A);
            dq.push_back(B);
        } else {
            dq.push_front(B);
            dq.push_back(A);
        }
    }
    dq.pop_front(); 
    while (!dq.empty()) {
        cycle.push_back(dq.front());
        dq.pop_front();
    }

    while (q--) {
        long long m;
        cin >> m;

        if (m <= preCycle.size()) {
            cout << preCycle[m - 1].first << " " << preCycle[m - 1].second << endl;
        } else {
            int index = (m - preCycle.size() - 1) % cycle.size();
            cout << mx << " " << cycle[index] << endl;
        }
    }

    return 0;
}
