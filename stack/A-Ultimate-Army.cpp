#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<int> st;
    vector<int> ans(n+1);
    string cur = "";
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if(cur != "") st.push(stoi(cur));
            cur = "";
        } else if (s[i] == ')') {
            if (cur != "") {
                ans[stoi(cur)] = st.top();
                cur = "";
            } else {
                int x = st.top();
                st.pop();
                ans[x] = st.top();
            }
        } else cur += s[i];
    }
    for(int i = 1; i <=n; i++) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}