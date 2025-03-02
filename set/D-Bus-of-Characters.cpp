/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    set<pair<int,int>> st;
    string q; cin >> q;
    int i  = 0;
    for(auto x : q) {
        if (x == '0') {
            cout << v[i].second+1;
            st.insert({v[i].first, v[i].second+1});
            i++;
        } else {
            cout << st.rbegin()->second;
            st.erase(--st.end());
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}