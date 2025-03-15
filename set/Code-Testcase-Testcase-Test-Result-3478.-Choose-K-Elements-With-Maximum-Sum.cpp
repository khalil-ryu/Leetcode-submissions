class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
            set<pair<int, int>> st1;
            int n = nums1.size();
            for (int i = 0; i < n ; i++) {
                st1.insert({nums1[i], i});
            }
            multiset<long long> st2;
            vector<long long> ans(n);
            long long sum = 0;
            vector<pair<long long, int>> last;
            for (auto &n : st1) {  
                if (last.size() && last[last.size()-1].first != n.first) {
                    for(int i = 0; i < last.size(); i++) {
                        st2.insert(nums2[last[i].second]);
                        sum += nums2[last[i].second];
                        if (st2.size() > k) {
                            sum -= *st2.begin();
                            st2.erase(st2.begin());
                        }  
                    }   
                    last.clear();
                } 
                ans[n.second] = sum; 
                last.push_back({n.first, n.second});
                
            }
            return ans;
        }
    };
    