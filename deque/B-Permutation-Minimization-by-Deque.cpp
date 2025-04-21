#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        std::deque<int> dq;
        for(int i=0; i<n ; i++){
            int curr ;
            cin >> curr;
            if(dq.empty()) dq.push_front(curr);
            else if(curr<=dq.front()) dq.push_front(curr);
            else dq.push_back(curr);
        }
        for (auto &x : dq)cout << x << ' ';
        cout << endl;
    }    

    return 0;
}