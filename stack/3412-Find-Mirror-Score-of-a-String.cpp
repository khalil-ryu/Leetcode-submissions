class Solution {
    public:
        long long calculateScore(string s) {
            map<int, stack<int>> mp;
            long long res = 0;
            for(int i = 0 ; i < s.size() ; i++) {
                if (mp.find('z'-s[i]) == mp.end()) mp[s[i]-'a'].push(i);
            else {
                    res += i-mp['z'-s[i]].top();
                    mp['z'-s[i]].pop();
                    if (mp['z'-s[i]].empty()) mp.erase('z'-s[i]);
                }
            }
            return res;
        }
    };