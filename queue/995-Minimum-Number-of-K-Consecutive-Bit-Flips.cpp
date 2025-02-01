class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int n = nums.size();
        int flips = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            while(q.size()) {
                int cur = q.front();
                if (cur < i) q.pop();
                else break;
            }
            if (!nums[i]) {
                if (q.size()%2 == 0) {
                    if(i+k-1 >= n) return -1;
                    q.push(i+k-1);
                    cnt++;
                }
            } else {
                if (q.size()%2 != 0) {
                    if(i+k-1 >= n) return -1;
                    q.push(i+k-1);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};