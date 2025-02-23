class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            queue<pair<int,int>> q;
            int n = tickets.size();
            for(int i = 0; i < n; i++) {
                q.push(make_pair(i, tickets[i]));
            }
            int ans = 0;
            while(!q.empty()) {
                pair<int,int> cur = q.front(); // > 1
                q.pop();
                if (cur.second > 1) q.push(make_pair(cur.first, cur.second-1));
                ans++;
                if (cur.second == 1 && cur.first == k) return ans;
            }
            return 0;
        }
    };