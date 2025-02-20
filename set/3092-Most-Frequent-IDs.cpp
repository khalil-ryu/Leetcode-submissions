class Solution {
    public:
        vector<long long> mostFrequentIDs(vector<int>& n, vector<int>& f) {
            unordered_map<int, long long> mp;
            set<pair<long long, int>> st; 
            vector<long long> res;
            for (int i = 0 ; i < n.size() ; i++) {
                st.erase({mp[n[i]], n[i]});
                mp[n[i]] += f[i];
                if (mp[n[i]]) st.insert({mp[n[i]], n[i]});
                else mp.erase(n[i]);
                if (st.empty()) res.push_back(0);
                else res.push_back(st.rbegin()->first);
            }
            return res;
        }
    };