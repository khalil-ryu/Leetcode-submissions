class Solution {
    public:
        string removeOuterParentheses(string s) {
            int cnt = 0;
            string ans, current;
            for(auto & c : s) {
                if (c == '(') {
                    current += c;
                    cnt++;
                } else {
                    current += c;
                    cnt--;
                }
                if (cnt == 0) {
                    ans += current.substr(1, current.size()-2);
                    current = "";
                }
            }
            return ans;   
        }
    };